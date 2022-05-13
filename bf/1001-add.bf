,                       (input to cell 0)
>,                      (input to cell 1)
<                       (move to cell 0)
[                       (open loop)
    ->                  (substract 1 to cell 0 and move to cell 1)
    +<                  (add 1 to cell 1 and return to cell 0)
]                       (close loop)                 

(convert to ASCII)

>>++++++++              (add 8 to cell 2)
[
    <------             (move to cell 1 and substract 6)
    >-                  (move to cell 2 and substract 1)
]

<.                      (move to cell 1 and print)
