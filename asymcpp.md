
# Table of Contents
- [Table of Contents](#table-of-contents)
- [Algorithms and Proving Correctness](#algorithms-and-proving-correctness)
  - [Proving Correctness](#proving-correctness)
- [Asymptotic Analysis](#asymptotic-analysis)
  - [Asymptotic Notation](#asymptotic-notation)
    - [Big O Notation](#big-o-notation)
    - [Big Ω Notation](#big-ω-notation)
    - [Big Θ Notation](#big-θ-notation)
    - [Tight vs Loose](#tight-vs-loose)
    - [Little Notations](#little-notations)
    - [CS Applications](#cs-applications)
      - [Insertion Sort](#insertion-sort)
- [Solving Recurrences](#solving-recurrences)
- [Quicksort](#quicksort)
- [Appendix](#appendix)
  - [Asymptotic Relational Properties](#asymptotic-relational-properties)
  - [Rules of Logarithms](#rules-of-logarithms)

*All images taken from Introduction to Algorithms, CLRS, 3rd edition*

# Algorithms and Proving Correctness
----
Algorithms are computational procedures that transform input into output\
\
Important questions to ask when analyzing an algorithm:
- Does the algorithm terminate?
- Is the algorithm correct?
- What is the efficiency of the algorithm?

## Proving Correctness

Algorithms with loops should maintain a ***loop invariant*** and should contain 3 processes:
- Initialization
- Maintenance
- Termination

A ***loop invariant*** is a statement that is true, before and after a loop iteration. It is true before the iteration starts, and after the iteration ends. This statement is helpful to prove that the algorithm terminates correctly. For example, in insertion sort, the loop invariant would be *"The array is sorted up to index i before the iteration starts, and since the loop sorts the array, the array is also sorted after the iteration ends"*

***Initialization*** -  The loop invariant holds before the first iteration
***Maintenance*** - If its true before the i'th iteration, it will be true before the (i+1)'st iteration
***Termintation*** - The loop invariant is true at the end of the last iteration
# Asymptotic Analysis
----
Asymptotic analysis is used to describe the running time of algorithms as the size of the input increases. For example if 'n' represented the input size of a given function, we can say that f(n) represents the runtime of that same function.

We use __*asymptotic notaions*__ such as big-theta (Θ), big-O (O), and big-omega (Ω) to generalize the performance of out runtime function *f(n)* over a long period of time. We do this because as time goes on, some constants or other functions of n inside of our runtime function become obsolete and insignificant compared to the highest order term.\
\
For example, let `f(n) = n^2 + 2n + 1000`. You may think that 1000 will overpower the function for low values of n, but as n increases, for example, to 10000, we can clearly say that `10000^2` is a *much* greater term than 1000 or even 2n. For that reason, we drop all terms that are lower than the highest order term in the function. In this case, the highest order term is `n^2`, so the asymptotic notation of `f(n)` would be `O(n^2)` "big-oh of n squared". We will talk about what "big O" and what the other terms mean next.

## Asymptotic Notation

We have already seen a few of the notations used in asymptotic analysis such as O, Θ, Ω, but what do they mean in regards to a runtime function f(n)?

### Big O Notation

The O notation or "big-oh" notation refers to the asymptotic upper bound of a function. It is simply the worst case analysis of an algorithm.

![image](https://user-images.githubusercontent.com/88636893/215837958-becb596b-7c8b-46ef-80c8-b7b7c78ea500.png)

For a given function g(n), The formal definition of O(g(n)) is as follows:\
`O(g(n)) = {f(n): there exist positive constants c and n0 such that 0 ≤ f(n) ≤ cg(n) for all n ≥ n0}`\
This is saying that O(g(n)) represents the *set* of functions, that after an input size of n0 "n naught", will never be ***greater*** than c * g(n).\
\
Let's see an example:\
let `f(n) = n^2 + 2n + 100`, and `f(n) = O(n^2)`. This means that the function `n^2 + 2n + 100` is an *element* of O(n^2), or 
`f(n) ∈ O(n^2)`, because there exists some constant `c` and `n0` such that `c * n^2` grows *faster* than `n^2 + 2n + 100`. Okay, but what are c and n0 doing and why do we need them? c is any constant that can make this inequality true. In our example above we could say that c is equal to 2. This would result in an inequality like so:  `0 ≤ n^2 + 2n + 100 ≤ 2 * n^2`. This is principally true because `2 * n^2` grows faster than `n^2 + 2n + 100`, but what about small values of n like 3? Lets plug in 3 and see if the inequality holds.

``` 
0 ≤ 3^2 + 2*3 + 100 ≤ 2 * 3^2
0 ≤ 9 + 6 + 100 ≤ 2 * 9
0 ≤ 115 ≤ 18
```

Well, 18 is not greater than 115 so the inequality is false. How do we fix this? By defining a "crossing point" in input size where after that crossing point, c * g(n) is *always* greater than f(n). This crossing point is called n0. n0 is reliant on c so if you had a different c value, you would find that your n0 would most likely be different.

### Big Ω Notation

Big Ω notation "big omega" is very similar to big O, but it represents the lower bound of a function, or the best case analysis of an algorithm. This notation is rarely used in the real world because the best case is not a great way to analyze an algorithm. If your algorithm runs in linear time for only one unique set of inputs, but in exponential time for all other inputs, it would be inaccurate to represent the *entire* function as O(n)

![image](https://user-images.githubusercontent.com/88636893/215838325-477731bf-d26b-4a36-8892-2a977037452d.png)


For a given function g(n), The formal definition of Ω(g(n)) is as follows:\
`Ω(g(n)) = {f(n): there exist positive constants c and n0 such that 0 ≤ cg(n) ≤ f(n) for all n ≥ n0}`\
Ω(g(n)) represents the *set* of functions, that after an input size of n0 "n naught", will never be ***less*** than c * g(n).

### Big Θ Notation

Big Θ notation "big theta" basically combines big O and big Ω and represents the *average* case runtime for an algorithm. This means it has an upper bound as well as a lower bound. 

![image](https://user-images.githubusercontent.com/88636893/215843151-d53e5599-c58b-4770-9d49-99798252e0c5.png)


For a given function g(n),
`Θ(g(n)) = {f(n): there exist positive constants c1, c2, and n0 such that 0 ≤ c1g(n) ≤ f(n) ≤ c2g(n) for all n ≥ n0}`
g(n) is the same function in the upper and lower bound, but they differ by a constant value. In order for a function f(n) to be Θ(g(n)), it must lie between these bounds when a $c_1$, $c_2$, and $n_0$ are properly chosen. ***f(n) must also be growing at the same rate as g(n).*** This means that we can't have something like $n = Θ(n^2)$. This doesn't work because you can't fit $n$ between two functions of $n^2$. Both $n^2$ functions will be on the upper bound $n$ and you won't have any lower bound making the inequality false: $$c_1n^2 \leq n \leq c_2n^2 $$ $$n\textnormal { can never be greater than a constant multiple of }  n^2$$

### Tight vs Loose

### Little Notations

### CS Applications

#### Insertion Sort



# Solving Recurrences

# Quicksort

- behavior of quickdort depends on the relative ordering of the values
- The runtime of Quicksort is `O(nlogn)` whenever the split has a constant proportionality. This means that the split isn't one-sided. For example, if your array has 10 elements, a split with constant proportionality could have a $\frac{4}{10}$ & $\frac{6}{10}$ split.
- 

Pseudocode
```
Partition(Arr, start, end)
  pivot = Arr[end] // set pivot to end element
  i = start-1      // 
  for j = start to (end - 1)
    if Arr[j] <= pivot
      i = i + 1
      swap(Arr[i], Arr[j])
  swap(Arr[i + 1], Arr[end])
  return i + 1
```

# Appendix
----
## Asymptotic Relational Properties

**Transivity**
![image](https://user-images.githubusercontent.com/88636893/216405218-8b18c30c-4571-46b4-bb84-5549149d272f.png)

**Reflexivity**
![image](https://user-images.githubusercontent.com/88636893/216405617-5ca13044-a96f-463c-98cb-302d2b8e93eb.png)

**Symmetry**
![image](https://user-images.githubusercontent.com/88636893/216405887-5ea85972-b660-4af5-b3f5-f7b93adbc79a.png)

**Transpose Symmetry**
![image](https://user-images.githubusercontent.com/88636893/216406013-9c36b60f-7ad1-47d2-907e-0252eacedf37.png)


## Rules of Logarithms


