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


%run
father(ram, shyam).
mother(seeta, sita).
father(X, shyam).
sibling(X, sita).
