/**
 *  @file syntax_tree.hpp
 *  Abstract Syntax Tree
 *
 *  @author Michael John Decker, Ph.D.
 *  Copyright 2018 Bowling Green State University. All rights reserved.
 *
 */

#ifndef INCLUDES_SYNTAX_TREE_HPP
#define INCLUDES_SYNTAX_TREE_HPP

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <list>
#include <vector>
#include <string>
#include <algorithm>

class syntax_tree;
enum nodes { category, token, whitespace };

bool                     is_coverage_tag (const std::string &);
std::string              read_until (std::istream &, char);
std::string              un_escape  (std::string);
std::vector<std::string> tokenize  (const std::string & s);


/**
 * An syntax_tree is either a:
 *     -Syntactic category node
 *     -Token node
 *     -Whitespace node
 *
 * @invariant: if (nodeType == category)
 *            than (child != 0) && (text == "")
 *            if ((nodeType == token) || (nodeType == whitespace))
 *            then (child == 0) && (text != "")
 */
class syntax_tree {
private:
    // category, token, or whitespace
    nodes node_type;

    // category: the tag name and
    std::string tag;
    // closing tag.
    std::string close_tag;

    // category: A list of subtrees. otherwise: empty() == true.
    std::list<syntax_tree *> children;

    // token/whitespace: the text.
    std::string text;

public:
    syntax_tree() {};
    syntax_tree(nodes t) : node_type(t) {};
    syntax_tree(nodes t, const std::string &);
    syntax_tree(const syntax_tree &);

    ~syntax_tree();

    void swap(syntax_tree &);
    syntax_tree & operator= (syntax_tree);

    syntax_tree * copy_syntax_tree();
    syntax_tree * get_child(std::string);
    std::string   get_name() const;

    void main_header(std::vector<std::string> &);
    void file_header(const std::string &);
    void main_report(std::vector<std::string> &);
    void instrument_functions(const std::string &);
    size_t count_elements() const;
    void instrument_statements(const std::string &, size_t & current_statement_number);

    std::ostream & print     (std::ostream &) const;
    std::istream & read      (std::istream &);

};


/**
 * srcml is an internal data structure for a srcML input file.
 * @invariant: Assigned(tree)
 */
class srcml {
private:
    std::string header;
    syntax_tree * tree;

public:
    srcml() : tree(nullptr) {};
    srcml(const srcml &);

    ~srcml() { delete tree; }

    void    swap      (srcml &);
    srcml & operator= (srcml);

    void main_header  (std::vector<std::string> &);
    void file_header  (const std::string &);
    void main_report  (std::vector<std::string> &);
    void instrument_functions(const std::string &);

    friend std::istream & operator>>(std::istream &, srcml &);
    friend std::ostream & operator<<(std::ostream &, const srcml &);

};


#endif
