% Facts about relationships
parent(john, bob).
parent(john, lisa).
parent(mary, bob).
parent(mary, lisa).
parent(bob, ann).
parent(bob, mike).
parent(lisa, carol).

% Rules
father(X, Y) :- parent(X, Y), male(X).
mother(X, Y) :- parent(X, Y), female(X).
grandparent(X, Z) :- parent(X, Y), parent(Y, Z).
sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.

% Facts about gender
male(john).
male(bob).
male(mike).
female(mary).
female(lisa).
female(ann).
female(carol).

% Queries examples:
% ?- father(john, bob).
% ?- mother(mary, lisa).
% ?- grandparent(john, ann).
% ?- sibling(ann, mike).