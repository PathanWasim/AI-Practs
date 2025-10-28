% Medical Diagnosis Expert System

% Symptoms database
symptom(fever).
symptom(cough).
symptom(headache).
symptom(sore_throat).
symptom(runny_nose).
symptom(body_ache).
symptom(fatigue).

% Disease rules
disease(cold) :-
    has_symptom(runny_nose),
    has_symptom(sore_throat),
    has_symptom(cough),
    not(has_symptom(fever)).

disease(flu) :-
    has_symptom(fever),
    has_symptom(body_ache),
    has_symptom(fatigue),
    has_symptom(headache).

disease(covid19) :-
    has_symptom(fever),
    has_symptom(cough),
    has_symptom(fatigue),
    has_symptom(body_ache),
    has_symptom(sore_throat).

% Treatment recommendations
treatment(cold) :-
    write('Recommended treatment for Cold:'), nl,
    write('1. Rest'), nl,
    write('2. Drink plenty of fluids'), nl,
    write('3. Over-the-counter cold medications'), nl.

treatment(flu) :-
    write('Recommended treatment for Flu:'), nl,
    write('1. Bed rest'), nl,
    write('2. Antiviral medications'), nl,
    write('3. Pain relievers'), nl,
    write('4. Stay hydrated'), nl.

treatment(covid19) :-
    write('Recommended treatment for COVID-19:'), nl,
    write('1. Isolate immediately'), nl,
    write('2. Contact healthcare provider'), nl,
    write('3. Monitor symptoms'), nl,
    write('4. Rest and hydration'), nl.

% Diagnosis interface
diagnose :-
    write('Answer these questions with y/n.'), nl,
    check_symptoms,
    find_disease.

check_symptoms :-
    retractall(user_symptom(_)),
    ask_symptom(fever),
    ask_symptom(cough),
    ask_symptom(headache),
    ask_symptom(sore_throat),
    ask_symptom(runny_nose),
    ask_symptom(body_ache),
    ask_symptom(fatigue).

ask_symptom(Symptom) :-
    write('Do you have '),
    write(Symptom),
    write('? (y/n) '),
    read(Answer),
    ( Answer = 'y' ->
        assert(user_symptom(Symptom))
    ; true
    ).

has_symptom(Symptom) :-
    user_symptom(Symptom).

find_disease :-
    disease(X),
    write('Based on the symptoms, you might have: '),
    write(X), nl,
    treatment(X).

% Example usage:
% ?- diagnose.