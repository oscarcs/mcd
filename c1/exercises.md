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
a) *What is the parse tree for the sentence `I see you`, in which `I` and `you` are terminal productions of `Personal_Pronoun` and `see` is a terminal production of `Verb`?



b) What would be a sensible AST for this parse tree?