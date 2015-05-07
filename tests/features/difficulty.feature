Feature: difficulty

    Several scenarios to test the connect four program depth feature. Difficulty can be 10-42 and is the dificulty level of the AI. "X" is computer, "O" is human.

    Scenario Outline: correct difficulty that should be used
        Given the input "<input>"
        When the connectfour program is run
        Then the output should be "<output>"



Examples:

|input     |output              |
|input.txt | expectedoutput1.txt|
|input2.txt| expectedoutput2.txt|
|input3.txt| expectedoutput3.txt|

