# Chapter 1
## Introduction

A *compiler* is a program that accepts as input a program text in a certain language and produces as output a program text in another language.
    
- This process is called *translation*.
- The translation takes place from a *source* language to a *target language*.
- The language the compiler is written in is called the *implementation language*.

An input program (or an output program) has a property called *semantics*, which refers to the meaning of the program that must be preserved in the translation process.

- The *semantic representation* of the language is the combination of the language semantics and the described structure of the language, e.g. given in a language refernence manual.
- The semantic representation of languages allows the compiler to collect the semantics of the target language and perform semantics-preserving synthesis of the target language.

The part of a compiler that performs the analysis of the source language text is called the *front-end*; the part that performs the synthesis is called the *back-end*.

- In a very cleanly-designed compiler, the front-end is unaware of the target language and the back-end is unaware of the source language.
- This very strict separation of the components of the compiler is often undesirable in practice.

A compiler that **performs** the actions specified by the semantic representation instead of performing program synthesis on the back-end is called an *interpreter*.

- Interpreters often improve portability and are easier to develop than a compiler back-end, but they are typically less efficient.

### 1.1 Why study compiler construction?

Why study compiler construction?

- ...because it is a success story in software engineering
- ...because it is a well-structured problem; in particular, the *analysis-synthesis paradigm* is a very powerful and widely applicable one. Compilers analyze the input, construct a semantic representation, and then synthesize output from it.
- ...because it makes judicious use of formalisms. There are highly standardized formalisms such as *regular expressions*, *context-free grammars*, and *attribute grammars*. The practical aspects of compiler construction can be taught without too much formalism, though.
- ...because one can learn how to write a program generator.
- ...because it has a wide applicability.
- ...because it contains generally-useful algorithms.

### 1.2 A simple traditional modular compiler / interpreter

The heart of a compiler is the semantic representation of the program being compiled, which typically takes the form of a data structure called the *intermediate representation*.

- There are two usual choices for the intermediate representation: a linked list of pseudoinstructions, or an annotated abstract syntax tree.

The *syntax tree* of a program is a data structure which shows precisely how the various parts of a program text are to be viewed gramatically.

*Parsing* is the process of structuring a text according to a given grammar.

- Parsing is also called *syntax analysis*.
- Syntax trees are thus also called *parse trees*.
- The exact form of the grammar is usually not the most convenient to use as a data structure, so we create an *abstract syntax tree* (AST), which is modified to be more convenient.
- We can *annotate* a syntax tree with more detail about language semantics, to produce an *annotated abstract syntax tree*. Examples of annotations include type information, optimization information, etc.


