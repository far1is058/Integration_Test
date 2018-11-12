/**
 *  @file syntax_tree.cpp
 *  Abstract Syntax Tree
 *
 *  @author Michael John Decker, Ph.D.
 *  Copyright 2018 Bowling Green State University. All rights reserved.
 *
 */
#include <iostream>
#include "syntax_tree.hpp"

/////////////////////////////////////////////////////////////////////
// Copy constructor for srcml
//
srcml::srcml(const srcml & actual) {
    tree = new syntax_tree(*actual.tree);
}

/////////////////////////////////////////////////////////////////////
// Constant time swap for srcml
//
void srcml::swap(srcml & b) {

    std::string t_header = header;
    header = b.header;
    b.header = t_header;
    
    syntax_tree * temp = tree;
    tree = b.tree;
    b.tree = temp;
}

/////////////////////////////////////////////////////////////////////
// Assignment for srcml
//
srcml & srcml::operator=(srcml rhs) {
    swap(rhs);
    return *this;
}

/////////////////////////////////////////////////////////////////////
// Reads in and constructs a srcml object.
//
std::istream& operator>>(std::istream & in, srcml & src){
    char ch;
    if (!in.eof()) in >> ch;
    src.header = read_until(in, '>');
    if (!in.eof()) in >> ch;
    if (src.tree) delete src.tree;
    src.tree = new syntax_tree(category, read_until(in, '>'));
    src.tree->read(in);
    return in;
}


/////////////////////////////////////////////////////////////////////
// Prints out a srcml object
//
std::ostream & operator<<(std::ostream & out, const srcml & src){
    src.tree->print(out);
    return out;
}

/////////////////////////////////////////////////////////////////////
//  Adds in the includes and coverage_map variables
//
void srcml::main_header(std::vector<std::string> & coverage_names) {
    tree->main_header(coverage_names);
}

/////////////////////////////////////////////////////////////////////
//  Adds in the includes and coverage_map variables
//
void srcml::file_header(const std::string & coverage_map_name) {
    tree->file_header(coverage_map_name);
}


/////////////////////////////////////////////////////////////////////
// Adds in the report to the main.
//
void srcml::main_report(std::vector<std::string> & coverage_names) {
        tree->main_report(coverage_names);
}

/////////////////////////////////////////////////////////////////////
// Instruments each function
//
void srcml::instrument_functions(const std::string & coverage_name) {
    tree->instrument_functions(coverage_name);
}

    

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
// Constructs a category, token, or whitespace node for the tree.
//
syntax_tree::syntax_tree(nodes t, const std::string & s) {
    node_type = t;
    switch (node_type) {
        case category:
            tag = s;
            break;
        case token:
            text = un_escape(s);
            break;
        case whitespace:
            text = s;
            break;
    }
}


/////////////////////////////////////////////////////////////////////
// Destructor for syntax_tree
//
syntax_tree::~syntax_tree() {
  for(std::list<syntax_tree *>::iterator it = children.begin(); it != children.end(); ++it) {
    delete *it;
  }
}


/////////////////////////////////////////////////////////////////////
// Copy Constructor for syntax_tree
//
syntax_tree::syntax_tree(const syntax_tree & actual) {
  node_type = actual.node_type;
  tag = actual.tag;
  close_tag = actual.tag;
  text = actual.text;

  for(std::list<syntax_tree *>::const_iterator it = actual.children.begin(); it != actual.children.end(); ++it) {
    children.push_back(new syntax_tree(**it));
  }
}


/////////////////////////////////////////////////////////////////////
// Constant time swap for syntax_tree
//
void syntax_tree::swap(syntax_tree & b) {
  std::swap(node_type, b.node_type);
  tag.swap(b.tag);
  close_tag.swap(b.tag);
  text.swap(b.text);
  children.swap(b.children);
}

/////////////////////////////////////////////////////////////////////
// Assignment for syntax_tree
//
syntax_tree & syntax_tree::operator=(syntax_tree rhs) {
    swap(rhs);
    return *this;
}


/////////////////////////////////////////////////////////////////////
// Returns a pointer to child[i] where (child[i]->tag == tag_name)
//
syntax_tree * syntax_tree::get_child(std::string tag_name) {
    std::list<syntax_tree *>::iterator ptr = children.begin();
    while (ptr != children.end() && (*ptr)->tag != tag_name) {
	++ptr;
    }
    if(ptr == children.end()) return nullptr;
    return *ptr;
}


/////////////////////////////////////////////////////////////////////
// Returns the full name of a <name> node.
//
std::string syntax_tree::get_name() const {
    std::string result;
    if (children.front()->tag != "name") {
        result = children.front()->text;   //A simple name (e.g., main)
    } else {                            //A complex name (e.g., stack::push).
        result = children.front()->children.front()->text;
        result += "::";
        result += children.back()->children.front()->text;
    }
    return result;
}


/////////////////////////////////////////////////////////////////////
//  Adds in the includes and coverage_map Variables in a main file.
//
void syntax_tree::main_header(std::vector<std::string> & coverage_names) {
  // WRITE THIS FUNCTION

	
	std::list<syntax_tree*>::iterator index = children.begin();

	// Iterate until I find a function!
	while ((*index)->tag != "function") {
		++index;
	}
	
	
	children.insert(index, new syntax_tree(token, "#include \"coverage_map.hpp\"\n"));
	children.insert(index, new syntax_tree(token, "coverage_map_t " + coverage_names[0] + "(\"simple_main.cpp\");" + "\n"));
	children.insert(index, new syntax_tree(token, "coverage_map_t " + coverage_names[1] + "(\"foo.cpp\");" + "\n"));
	
	//children.insert(index, new syntax_tree(token, "This count = " + *count_elements() + "\n"));



}


/////////////////////////////////////////////////////////////////////
//  Adds in the includes and coverage_map variables for non-main files
//
void syntax_tree::file_header(const std::string & coverage_map_name) {
  // WRITE THIS FUNCTION
	
        std::list<syntax_tree*>::iterator index = children.begin();

        // Iterate until I find a function!
        while ((*index)->tag != "function") {
                ++index;
        }
        
        children.insert(index, new syntax_tree(token, "#include \"coverage_map.hpp\"\n"));
        children.insert(index, new syntax_tree(token, "extern coverage_map_t " + coverage_map_name + ";\n"));
	//children.insert(index, new syntax_tree(token, "extern coverage_map_t foo_cpp;\n"));


}


/////////////////////////////////////////////////////////////////////
// Adds in the report to the main.
// Assumes only one return at end of main body.
//
void syntax_tree::main_report(std::vector<std::string> & coverage_names) {
    // WRITE THIS FUNCTION	     

	std::list<syntax_tree*>::iterator index;// = children.begin();
	std::list<syntax_tree*>::iterator itr = get_child("function")->get_child("block")->children.begin();	 
	
	
	for (index=children.begin(); index!=children.end();index++){

		if(((*index)->tag == "function")&&((*index)->get_child("name")->get_name() == "main")){

			while((*itr)->tag != "return"){

                                ++itr;
				

                        }

			 if ((*itr)->tag == "return"){

                                        children.insert(itr, new syntax_tree(token, coverage_names[0]+".print();"+coverage_names[1]+".print();"));
                                        
                                }



		}

	}
	

        



					
	


}

/////////////////////////////////////////////////////////////////////
// Instruments function with coverage info
// This function needs to do the following:
//     Seach through all top level elements for function elements
//     When found do:
//         Gets the number of coverage elements (via count_elements)
//         Inserts a call to "coverage_map.append" after the block
//             Use __FUNCTION_NAME__ and the number of elements returned from count_element
//         Inserts calls to "coverage_map.executed" after each decl_stmt & expr_stmt and at the front of each condition
//             Do this via a call to instrument_statements
//
void syntax_tree::instrument_functions(const std::string & coverage_map_name) {
    // WRITE THIS FUNCTION
	size_t  eachcount = count_elements();
	 std::list<syntax_tree*>::iterator index = children.begin();
         std::list<syntax_tree*>::iterator itr = get_child("function")->get_child("block")->children.begin();
	//syntax_tree * child;

	while ((*index) -> tag != "function")
		++index;


	if ((*index)->tag == "function"){
			
		//children.insert(++itr, new syntax_tree(token, coverage_map_name + ".append(__FUNCTION__, );" ));
		

		//while ((*itr) -> tag != "expr_stmt" )
		//	++itr;


		//if ((*itr) -> tag == "expr_stmt" )
		//	children.insert( ++itr, new syntax_tree(token, coverage_map_name + ".executed(__FUNCTION__, );") );
		
		
	} 


}

/////////////////////////////////////////////////////////////////////
// Counts the number of expr_stmt, decl_stmt, & condition in a function body
//  Assumes no nested functions or ternary operato.
//
size_t syntax_tree::count_elements() const {
  // WRITE THIS FUNCTION
	size_t count =1;
	std::cout<<" I am before for \n";
	//------------------------------------------
	std::list<syntax_tree*>::const_iterator index ;
	
	

	for (index = children.begin(); ;index++){
		std::cout<<" I am inside for \n";
		
		if (index != children.end()){
			if ((*index) -> tag == "expr_stmt"){
				 ++count;
				return count;
			}

			else
				return count = 0;
		}
			
		
		
		
		
		else
			count_elements();

	}


	

	//-------------------------------------------
	
	//for (const syntax_tree * child:children){

		//if ( child -> tag == ( "expr_stmt") ) {
			
	//	std::cout<<" I am inside for \n";	
	//		 ++count;
			

		//}

		//else if ((*index) -> tag == "decl_stmt")

		//	count++;
		//else
	//		count_elements();

	//}
		
        


  return 0;
}

/////////////////////////////////////////////////////////////////////
// Inserts calls to "coverage_map.executed" after each decl_stmt & expr_stmt and at the front of each condition
//     Do this via a call to instruement_statements
//
void syntax_tree::instrument_statements(const std::string & coverage_map_name, size_t& current_statement_number) {
    // WRITE THIS FUNCTION
	current_statement_number = 0;
	       std::list<syntax_tree*>::iterator itr = get_child("function")->get_child("block")->children.begin();      
               std::list<syntax_tree*>::iterator index = children.begin();         
	//for (const syntax_tree * child:children){
		 while ((*index) -> tag != "function")
	                ++index;

		if ((*index)-> tag == "function"){

                	while ((*itr) -> tag != "expr_stmt" )
				++itr;
			if ( (*itr) -> tag == "expr_stmt" ) {
			//while ((*itr)->tag != "{" )
			//	++itr;
			//if ((*itr)->tag == "{")
                             children.insert(++itr, new syntax_tree(token, coverage_map_name+".executed(__FUNCTION__, );"));
			     current_statement_number++;
			}
			//else
			//	++itr;
			
                }


                else
                        instrument_statements(coverage_map_name,current_statement_number);

        //}


        






}

/////////////////////////////////////////////////////////////////////
// Read in and construct syntax_tree
// REQUIRES: '>' was previous charater read 
//           && this == new syntax_tree(category, "tag_name")
//
//
std::istream & syntax_tree::read(std::istream & in) {
    syntax_tree * subtree;
    std::string temp;
    char ch;
    if (!in.eof()) in.get(ch);
    while (!in.eof()) {
        if (ch == '<') {                      //Found a tag
            temp = read_until(in, '>');
            if (temp[0] == '/') {
                close_tag = temp;
                break;                        //Found close tag, stop recursion
            }
            subtree = new syntax_tree(category, temp);               //New subtree
            subtree->read(in);                               //Read it in
            in.get(ch);
            children.push_back(subtree);                        //Add it to child
        } else {                                             //Found a token
            temp = std::string(1, ch) + read_until(in, '<');  //Read it in.
            std::vector<std::string> token_list = tokenize(temp);
            for (std::vector<std::string>::const_iterator i = token_list.begin();
                 i != token_list.end(); ++i) {
                if (isspace((*i)[0])) {
                    subtree = new syntax_tree(whitespace, *i);
                } else {
                    subtree = new syntax_tree(token, *i);
                }
                children.push_back(subtree);
            }
            ch = '<';
        }
    }
    return in;
}


/////////////////////////////////////////////////////////////////////
// Print an syntax_tree 
// REQUIRES: indent >= 0
//
std::ostream & syntax_tree::print(std::ostream & out) const {
    for (std::list<syntax_tree *>::const_iterator i = children.begin();
         i != children.end(); ++i) {
        switch ((*i)->node_type) {
            case category:
                (*i)->print(out);
                break;
            case token:
                out << (*i)->text;
                break;
            case whitespace:
                out << (*i)->text;
                break;
        }
    }
    return out;
}

    

/////////////////////////////////////////////////////////////////////
// Utilities
//


/////////////////////////////////////////////////////////////////////
// This returns true if a syntactic category needs coverege inserted
// This is IMPORTANT
bool is_coverage_tag(const std::string & tag) {
    if (tag == "decl_stmt") return true;
    if (tag == "expr_stmt") return true;
    if (tag == "condition") return true;
    return false;
}


/////////////////////////////////////////////////////////////////////
// Reads until a key is encountered.  Does not include ch.
// REQUIRES: in.open()
// ENSURES: RetVal[i] != key for all i.
//
std::string read_until(std::istream & in, char key) {
    std::string result;
    char ch;
    in.get(ch);
    while (!in.eof() && (ch != key)) {
        result += ch;
        in.get(ch);
    }
    return result;
}


/////////////////////////////////////////////////////////////////////
// Converts escaped XML charaters back to charater form
// REQUIRES: s == "&lt;"
// ENSURES:  RetVal == "<"
//
std::string un_escape(std::string s) {
    std::size_t pos = 0;
    while ((pos = s.find("&gt;"))  != s.npos) { s.replace(pos, 4, ">");}
    while ((pos = s.find("&lt;"))  != s.npos) { s.replace(pos, 4, "<");}
    while ((pos = s.find("&amp;")) != s.npos) { s.replace(pos, 5, "&");}
    return s;
}


/////////////////////////////////////////////////////////////////////
// Given: s == "   a + c  "
// RetVal == {"   ", "a", " ", "+", "c", " "}  
//
std::vector<std::string> tokenize(const std::string & s) {
    std::vector<std::string> result;
    std::string temp = "";
    unsigned i = 0;
    while (i < s.length()) {
        while (isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
        while (!isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
    }
    return result;
}
    

