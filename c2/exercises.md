# Chapter 2 Exercises

2.4 *Somebody in a compiler construction project suggests solving the newline problem by systematically replacing all the newlines by spaces, since they mean the same thing. Why is this almost certainly wrong?*

This is probably wrong because semantically newlines and spaces mean different things in most languages, even in semicolon languages like C (where newlines are used to separate macros, among other things). The other consideration is that newlines are still useful to the lexer. Compilers generally have to provide helpful errors to users; an important part of most compiler error messages is the line number of the error, which helps the user track down the location of the error. Removing newlines throws away this information, making the errors worse than they would be otherwise.

2.6 *Give regular expressions for all sequences of 0s and 1s that:*

1. Contain exactly 2 1s.

>`/0*10*10*/`
>
> The string can contain any number of zeros between and around the two ones, but no more than two 1s are allowed.

2. Contain no consecutive 1s.

> The secret to this one is that any 1 must be followed by either a 0, or by the end of the matched string. The 'core loop' is to match any number of 0s, a 1 followed by a 0, and then any amount of 0s, like so:
>
> `/0*(10)*0*/`
> 
> We need to match at least one of these:
> 
> `/(0*(10)*0*)+/`
> 
> And then the final character can be a 1 (the special case). In order to not match any empty strings, we can also terminate with a 0:
> 
> `/(0*(10)*0*)+(1|0)/`

3. Contain an even number of 1s.

> This is similar to part 1, but we can have any even number instead of just 2:
> 
> `/0*(10*10*)*0*/`