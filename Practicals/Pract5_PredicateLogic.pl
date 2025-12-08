% Facts
parent(ram, shyam).
parent(seeta, shyam).
parent(ram, sita).
parent(seeta, sita).

male(ram).
male(shyam).
female(seeta).
female(sita).

% Rules
father(X, Y) :- parent(X, Y), male(X).
mother(X, Y) :- parent(X, Y), female(X).

sibling(X, Y) :-
    parent(P, X),
    parent(P, Y),
    X \= Y.

% Grandfather Rule
grandfather(X, Y) :-
    parent(X, Z),
    parent(Z, Y),
    male(X).

% Run / Queries
father(ram, shyam).
mother(seeta, sita).
father(X, shyam).
sibling(X, sita).
grandfather(X, sita).
