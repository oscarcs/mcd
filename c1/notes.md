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

*Refer to /democ for code for this section.*

The heart of a compiler is the semantic representation of the program being compiled, which typically takes the form of a data structure called the *intermediate representation*.

- There are two usual choices for the intermediate representation: a linked list of pseudoinstructions, or an annotated abstract syntax tree.

The *syntax tree* of a program is a data structure which shows precisely how the various parts of a program text are to be viewed gramatically.

*Parsing* is the process of structuring a text according to a given grammar.

- Parsing is also called *syntax analysis*.
- Syntax trees are thus also called *parse trees*.
- The exact form of the grammar is usually not the most convenient to use as a data structure, so we create an *abstract syntax tree* (AST), which is modified to be more convenient.
- We can *annotate* a syntax tree with more detail about language semantics, to produce an *annotated abstract syntax tree*. Examples of annotations include type information, optimization information, etc.

### 1.3 The structure of a more realistic compiler

A more realistic compiler would likely consist of modules on the front-end to handle the following:

- Lexical analysis (taking characters as input, and outputting tokens)
- Syntax analysis (taking tokens as input, outputting an AST)
- Context handling (taking an AST and outputting an annotated AST)
- Intermediate code generation

The back end would then take the intermediate code and include the following modules:

- An intermediate code optimizer (taking IC as input and optimizing it)
- A code generator (taking IC and outputting symbolic instructions)
- A target code optimizer (taking symbolic instructions and optimizing them)
- A machine code generator (taking symbolic instructions and outputting bit patterns)
- A binary outputter

### 1.4 Compiler architectures

We can talk about compilers being of different 'widths':

- A *narrow* compiler is one that reads a small part of the program, processes the information obtained, and produces output iteratively until the end of the program.
- A *broad* compiler reads the entire program and applies a series of transformations, which eventually result in a completely compiled program.

Note that this nomenclature doesn't appear to be in widespread use, though it is a helpful conceptual model. Many real compilers are a compromise between these two paradigms, e.g. a compiler that processes the entirety of each function individually.

A compiler may also have multiple phases or *passes*. Each pass makes transformations on the program to eventually reach the goal. A compiler with multiple passes is a *N-pass* compiler. Most compilers today do not consist of multiple passes, because of the additional complexity and reduction in efficiency that is involved with making additional passes, coupled with the increase in memory of modern computers.

We have a problem with modularizing the compiler, which is that each unit of the compiler contains a main loop which runs through the code. With multiple main loops, we have to cede control to the next stage of the compiler in order to perform processing, which in most languages means returning from a function (and losing the associated state on the stack). *Co-routines* are one way of solving this problem -- we have two stacks so that the two routines can run concurrently -- but they are not really implemented in most languages.

### 1.5 Properties of a good compiler

A non-exhaustive list of things a good compiler should do:

- Consistently generate correct code
- Conform to the language specification
- Should be able to handle programs of essentially arbitrary size
- Compile quickly
- Report errors clearly
- Should be secure

### 1.6 Portability and retargetability

A program is considered *portable* if it takes a limited and reasonable effort to make it run on different types of machines.

There are two types of portability with respect to compilers:

- The *portability* of the compiler itself, i.e. whether the compiler can run on different types of machines.
- The ease with which the compiler can be made to generate code for different machines; this is known as *retargetability*.

### 1.7 A short history of compiler construction

Here's the (very short) version, check the textbook for a slightly longer version.

- 1945-1960: Programming in anything more abstract than assembly was called 'automatic programming'. Nobody really did it. The first good compiler was for FORTRAN, developed in 1959 (!).
- 1960-1975: More emphasis on front-ends, including work in formal languages.
- 1975-now: Professionalization of compiler development, new programming language paradigms.

### 1.8 Grammars

Grammars are the essential formalism for describing the structure of programs in a programming language. In principle, the *grammar* of a language describes the syntactic structure only, but since the semantics are defined in terms of the syntax, the grammar is also important when it comes to defining semantics.

- The *context-free grammar* (CFG) is the main type of grammar that we are concerned with, although there are other types of grammars, including *regular grammars* (cf. regular expressions), and *attribute grammars*, which are CFGs extended with parameters and code.

A grammar consists of a set of production rules and a start symbol. Each production rule defines a named syntactic construct, and consists of two parts: a left hand side and a right hand side, separated by an arrow. The left hand side is the name of the construct, and the right hand side shows a possible form of the syntactic construct.

The right hand side of the production rule can consist of two types of symbols:

- A *terminal symbol* (also called a 'token'), which is an 'end point' of the production process, and can be part of the strings produced by the grammar.
- A *non-terminal symbol*, which appears as the left hand side of at least one other production rule.

A more formal definition of a 'grammar is as follows:

> A *generative grammar* G is an ordered quadruple G = (Vₙ, Vₜ, S, F) where Vₙ and Vₜ are finite alphabets, with Vₙ ∩ Vₜ = ∅, S is a *distinguished symbol* of Vₙ, and F is a finite set of ordered pairs (P, Q) such that P and Q are in (Vₙ ∪ Vₜ)* and P contains at least one symbol from Vₙ.

(Vₙ ∪ Vₜ)* refers to the Kleene closure (AKA the free monoid construction) of the union of the terminals Vₜ and the nonterminals Vₙ. 

We can derive a string of terminals from the start symbol by applying the rules of the grammar.

