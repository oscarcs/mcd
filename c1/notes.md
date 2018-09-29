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

We can *derive* a string of terminals from the start symbol by applying the rules of the grammar. In order to produce an infinite number of strings, grammars rely on recursion -- the ability of a production rule to refer directly or indirectly to itself.

Consider the following grammar:

```
expr -> (expr op expr)
expr -> 1
op -> +
op -> *
```

Given the string `(1 * (1 + 1))`, we can apply the grammar to derive this string, as follows:

```
expr
(expr op expr)
(1 op expr)
(1 * expr)
(1 * (expr op expr))
(1 * (1 op expr))
(1 * (1 + expr))
(1 * (1 + 1))
```

This is called the *leftmost derivation*, because at each step we rewrite the leftmost non-terminal.

There are other forms of grammars. The form `nonterminal -> zero or more grammar symbols` is sufficient to specify any grammar, but it is convenient to extend the notation. We can combine a set of rules like:

```
N -> a
N -> b
N -> c
```

Into the form `N -> a | b | c`. In this form, we speak of a, b, and c as being *alternatives*. This form is known as BNF, *Backus-Naur Form*. We can extend BNF, by adding three additional notations:

- `R+` indicates that there are one or more Rs, to express repetition.
- `R?` indicates that there are zero or one Rs, to express optionality.
- `R*` indicates that there are zero or more Rs, to express optional repetition.

Parentheses can be used if these operators are to operate on more than one symbol.

A non-terminal is *left-recursive* if, starting with a sentential (intermediate) form N, we can produce another sentential form starting with N. An example is:

```
expression -> expression + factor | factor
```

A grammar that contains one or more left-recursive rules is, by extension, a left-recursive grammar.

A non-terminal N is *nullable* if, starting with a sentential form N, we can produce an empty sentential form.

A non-terminal N is *useless* if it can never produce a string of terminal symbols. An example is:

```
expression -> + expression | - expression
```

A grammar is *ambiguous* if it can produce two different production trees with the leaves in the same order (if it can be parsed in two different ways). This means that when we linearize the program, we can't unambiguously recover the production tree.

The *language* generated by a grammar is the set of all terminal productions of that grammar. These terminal productions are called *sentences* in the grammar. e.g. if G is a grammar for a programming language, then L(G) is the set of all syntactically correct programs in that language.  

(Here, the textbook covers some of the formalisms of a grammar. I will cover these elsewhere, but see above.)

### 1.9 Closure Algorithms

In a general form, a *closure algorithm* exhibits the following three elements:

- *Data definitions*: The definitions and semantics of the information items. These derive from the nature of the problem
- *Initializations*: One or more rules for the initialization of the information items. These convert information from the specific problem onto information items.
- *Inference rules*: One or more rules of the form 'If information items I1, I2, ... are present then information item J must also be present'.

The *least fixed point* of the closure algorithm refers to the smallest set of information items that fulfills the rules in the closure algorithm.

A *general closure algorithm* has inference rules of the form "if information items I1, I2, ... are present, then information item j must also be present". A *transitive closure algorithm* is restricted to rules that fulfill the transitive property, i.e. "if information items (A, B) and (B, C) are present then information item (A, C) must be as well".

A closure algorithm is usually implemented iteratively by repeated bottom-up sweep. In this approach, the information items are visited in a systematic fashion to find sets of items that fulfill the condition of an inference rule. 

- A 'sweep' consists of finding the nodes of the graph one by one, and for each node, adding an edge from it to all of its descendants' descentants, as far as those are known. We then repeat this process until no more edges can be added.

- This algorithm, which is called is rather inefficient. The best algorithm (Warshall's Algorithm) runs in O^3 time, which is not a great running time; real world graphs tend to have properties (e.g. they are sparse) that make this less of an issue, however.