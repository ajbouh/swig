/* -----------------------------------------------------------------------------
 * This file is part of SWIG, which is licensed as a whole under version 3 
 * (or any later version) of the GNU General Public License. Some additional
 * terms also apply to certain portions of SWIG. The full details of the SWIG
 * license and copyrights can be found in the LICENSE and COPYRIGHT files
 * included with the SWIG source code as distributed by the SWIG developers
 * and at http://www.swig.org/legal.html.
 *
 * DoxygenTranslator.h
 *
 * Module to return documentation for nodes formatted for various documentation
 * systems.
 * ----------------------------------------------------------------------------- */

#ifndef DOXYGENTRANSLATOR_H_
#define DOXYGENTRANSLATOR_H_

#include "swig.h"
#include "DoxygenEntity.h"
#include "DoxygenParser.h"
#include <list>


/*
 * A class to translate doxygen comments attached to parser nodes
 * into alternative formats for use in code generated for target languages.
 */
class DoxygenTranslator {
public:
  /*
   * Constructor
   */
  DoxygenTranslator(bool debugTranslator = false, bool debugParser = false);
  /*
   * Virtual destructor.
   */
  virtual ~ DoxygenTranslator();
  /*
   * Return the documentation for a given node formated for the correct 
   * documentation system.
   */
  String *getDocumentation(Node *node);
  /*
   * Whether the specified node has comment or not
   */
  bool hasDocumentation(Node *node);
  /*
   * Get original, Doxygen-format comment string
   */
  String *getDoxygenComment(Node *node);

protected:
  bool debug;
  /*
   * Overridden in subclasses to return the documentation formatted for a given
   * documentation system.
   */
  virtual String *makeDocumentation(Node *node) = 0;
  
  /*
   * Prints the details of a parsed entity list to stdout (for debugging).
   */
  void printTree(std::list < DoxygenEntity > &entityList);
  
  /*
   * Doxygen parser object
   */
  DoxygenParser parser;
};

#endif
