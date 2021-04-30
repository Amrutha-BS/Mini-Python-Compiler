# Mini-Python-Compiler

This project being a Mini Compiler for the Python language, focuses on generating
an intermediate code for the language for specific constructs. It works for constructs
such as if-else, for and basic arithmetic operations.
The main functionality of the project is to generate an optimized intermediate
code for the given python source code.

This is done using the following steps:
i) Generate symbol table after performing expression evaluation
ii) Syntax and Semantic Analysis
iii) Generate 3 address code followed by corresponding quadruples
iv) Perform Code Optimization

The main tools used in the project include LEX which identifies predefined
patterns and generates tokens for the patterns matched and YACC which
parses the input for semantic meaning and generates intermediate code for the
given source code.
Further, the generated intermediate code is optimized. The Syntax and
Semantic errors are being handled in Error Handling part. In this project following four code optimisation methods are implemented:

1. Constant propagation
2. Constant folding
3. Dead Code Elimination
4. Copy Propagation.
