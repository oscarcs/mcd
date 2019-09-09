# Notes and commentary on papers by Chomsky

This file contains some notes and commentary on the original formal language papers of Noam Chomsky.

## Three Models for the Description of Language

This paper is about using different models of linguistic structure, to investigate which of them can provide grammars that can generate all of the sentences in English and only those sentences.

### Introduction

Chomsky first discusses what he considers to be the two central problems in linguistics that he hopes to contribute to. These problems are to discover maximally simple and expressive grammars for languages, and to create a general theory of languages and linguistic structure. He then discusses what he considers a grammar to be: 'an account of how finite observations of languages can be explained in terms of their interrelation, and using this account to make future predictions'. Chomsky points out that a mathematical model of grammar is desirable because it can be more rigourously used to make predictions, and can be used to establish general laws and eliminate ambiguity.

Chomsky explicates his theory of linguistics a step further: "Linguistic theory attempts to explain the ability of a speaker to produce and understand new sentences, on the basis of his limited linguistic experience." In my opinion, this is a beautifully clear explanation of what linguistics is about. Chomsky goes on to provide an example of how this goal might be accomplished, and then he lays out the purpose of the paper: to discover the type of formal structure that might be required to represent English grammar.

What follows are some important definitions. A *language* is a set (finite or infinite) of sentences, each of infinite length, all constructed from a finite alphabet of symbols. The fact that Chomsky allows an infinite language follows from the definition of linguistics above: there may be infinite possible valid sentences in English. Constrast this with the definition of *grammar* that follows: a grammar of language L is a **finite** device that produces all of the strings that are sentences of L and only those sentences. A grammar must be finite, because an English speaker can only have a finite amount of grammar in their head.

Chomsky then introduces some of the criteria that he will use to judge different grammar structures:

- Are there interesting languages that are simply outside the range of description of the proposed type?
- Can we construct reasonably simple grammars for all interesting languages?
- Are such grammars 'revealing' in the sense that the syntactic structure that they exhibit can support semantic analysis, can provide insight into the use and understanding of language, etc.?

### Finite State Markov Processes

Chomsky calls finite-state Markov processes "the most elementary grammars which, with a finite amount of apparatus, will generate an infinite number of sentences". A finite-state Markov process is a random process on a finite graph of states. For each state, you specify the probability of transitioning to a new state. We can use this transition process as a grammar.

Chomsky looks at the limit of this type of process. He introduces the idea of 'dependency'. An i,j dependency exists in a sentence of a particular language if, when we consider two symbols in that sentence, swapping one of the symbols leads to an ungrammatical sentence that can be fixed by then also swapping the other symbol. For example: 

- Mary persuaded John to wash himself with soap.
- \* Mary persuaded **Sue** to wash himself with soap.
- Mary persuaded **Sue** to wash **herself** with soap.

**John** and **himself** have an i,j dependency in the first sentence. Chomsky then says we can construct the 'dependency set' for a sentence by looking at all of the indexes i,j of the symbols in the sentence that are dependent on each other. Chomsky uses this idea to (very tersely) prove some properties of regular languages. 

We can think of the dependency sets as a graph colouring problem. For each of the first symbols of the dependency pair, we take a colour. If we reach the start of a different dependency pair before we reach the second member of our current pair, we colour that new dependency pair with a new colour. We reuse colours after the end of a dependency pair. The number of colours we needed to use gives us a measure of the amount of state we have to 'remember' in order to get the dependencies right. Chomsky claims that for any regular language, there's a *constant number* of colours that can be used for the dependency set of any sentence in the language.

Chomsky says that this implies English is not modellable using regular languages. He uses some examples to demonstrate that grammatical English sentences with dependency sets requiring an arbitrary number of colours can be constructed (he does not use this terminology explicitly). After this, Chomsky goes on a bit of a tangent about the use of the Markov language model for a statistical approximation of English grammar. He says that it's mostly pointless to use a Markov statistical approximation of English grammar, because a sentence like 'colorless green ideas sleep furiously' is a very unlikely series of words, but it is completely grammatical. He makes the strong claim that "we are forced to conclude that there is apparently no significant approach to the problems of grammar in this direction".