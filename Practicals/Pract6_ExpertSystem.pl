%Facts
symptom(fever, high).
symptom(cough, yes).
symptom(headache, yes).
symptom(runny_nose, no).

%Rules
disease(flu) :-
    symptom(fever, high),
    symptom(cough, yes),
    symptom(headache, yes).

disease(cold) :-
    symptom(runny_nose, yes),
    symptom(cough, yes),
    symptom(fever, low).

advice(flu, 'Take rest and drink warm fluids.').
advice(cold, 'Drink water and take steam.').

%inference
diagnose :-
    disease(D),
    write('You may have: '),
    write(D), nl,
    advice(D, A),
    write(A), nl.

%run 
diagnose.