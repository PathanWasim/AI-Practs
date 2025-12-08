%========================
% PATIENT SYMPTOMS (FACTS)
%========================

symptom(fever, high).
symptom(cough, yes).
symptom(headache, yes).
symptom(runny_nose, no).
symptom(body_pain, yes).
symptom(sore_throat, yes).
symptom(breathing_problem, no).
symptom(fatigue, yes).
symptom(vomiting, no).
symptom(diarrhea, no).

%========================
% DISEASE RULES
%========================

% Flu
disease(flu) :-
    symptom(fever, high),
    symptom(cough, yes),
    symptom(headache, yes),
    symptom(body_pain, yes).

% Cold
disease(cold) :-
    symptom(runny_nose, yes),
    symptom(cough, yes),
    symptom(fever, low).

% COVID-19
disease(covid) :-
    symptom(fever, high),
    symptom(cough, yes),
    symptom(breathing_problem, yes),
    symptom(fatigue, yes).

% Food Poisoning
disease(food_poisoning) :-
    symptom(vomiting, yes),
    symptom(diarrhea, yes),
    symptom(fever, high).

% Migraine
disease(migraine) :-
    symptom(headache, yes),
    symptom(fever, no),
    symptom(vomiting, no).

%========================
% ADVICE / TREATMENT
%========================

advice(flu, 'Take rest, drink warm fluids and consult a doctor if fever persists.').
advice(cold, 'Drink warm water, take steam and rest.').
advice(covid, 'Isolate yourself, get tested and seek medical help immediately.').
advice(food_poisoning, 'Drink ORS, avoid outside food and consult a doctor.').
advice(migraine, 'Take proper sleep, avoid bright light and consult neurologist.').

%========================
% PRECAUTIONS
%========================

precaution(flu, 'Wash hands regularly and avoid cold exposure.').
precaution(cold, 'Avoid cold drinks and dusty environments.').
precaution(covid, 'Wear mask, maintain distance and sanitize hands regularly.').
precaution(food_poisoning, 'Eat fresh food and drink clean water.').
precaution(migraine, 'Avoid stress and bright screens.').

%========================
% INFERENCE ENGINE
%========================

diagnose :-
    disease(D),
    write('----------------------------------'), nl,
    write('You may have: '), write(D), nl,
    advice(D, A),
    write('Advice: '), write(A), nl,
    precaution(D, P),
    write('Precaution: '), write(P), nl,
    write('----------------------------------'), nl.

%========================
% RUN
%========================

start :-
    write('Medical Expert System'), nl,
    write('Diagnosing based on given symptoms...'), nl,
    diagnose.
