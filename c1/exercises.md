# Chapter 1 Exercises

1.1. *Compilers are often written in the language they implement. Identify advantages and disadvantages of this technique.*

An advantage of this technique is that the development of the compiler is a large real-world project that will be useful for evaluating the language design. On the other hand, writing a compiler in the language that it is written in requires the development of a bootstrapping compiler, which will be written in another language. This means that the developers will have to write two compilers instead of just one.

1.2. *Referring to Section 1.1.1.1, give additional examples of why a language front-end would need information about the target machine and why a back-end would need information about the source language.*

A language front-end would need information about the target architecture to parse inline assembly code in the source language. A language back-end might need to know something about whether side effects are intended in the source language in order to compile code correctly.

1.4 *Given the following incomplete grammar for a very simple segment of English:*

```
Sentence -> Subject Verb Object
Subject -> Noun_Phrase
Object -> Noun_Phrase
Noun_Phrase -> Noun_Compound | Personal_Name | Personal_Pronoun
Noun_Compound -> Article? Adjective_Sequence? Noun
```
a) *What is the parse tree for the sentence `I see you`, in which `I` and `you` are terminal productions of `Personal_Pronoun` and `see` is a terminal production of `Verb`?*

```
                   Sentence
             Subject Verb Object
        Noun_Phrase    |     Noun_Phrase
Personal_Pronoun       |        Personal_Pronoun
      I               see             you
```

b) *What would be a sensible AST for this parse tree?*
```
    see
  /    \  
I       you
```

1.10 *Is the compiler implemented in Chapter 1 a 'narrow' or 'broad' compiler?*

The compiler in Chapter 1 is a narrow compiler, because it applies transformations iteratively by transforming parts of the program.

1.13 *What is an 'extended subset' of a language? Why is the term usually used in a perjorative sense?*

An 'extended subset' is a subset of the features of the language that have been augmented by more features that are not part of the specification. It is usually used pejoratively to disparage someone who is too lazy to implement the entire language properly.

1.18 *Why would it be considered bad design to have a terminal symbol with an empty representation?*

This would be considered bad design because any use of the empty string symbol could be replaced by other ways of conveying the same information that are clearer. For example, we could use the 'optionality' symbol of EBNF, '?', to represent the scenario when e.g. `non-terminal -> terminal | ε`
