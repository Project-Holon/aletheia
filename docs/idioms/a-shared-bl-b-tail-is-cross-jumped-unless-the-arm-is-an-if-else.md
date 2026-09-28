# Two switch arms ending in the same call and `b` are cross-jumped unless one arm is an if/else

summary: in a switch whose arms end `mov r0, #k; bl f; b exit`, an arm written as
`if (c != 3) { move = 2; break; } ...; f(0); break;` lets 1.1p1 fold another arm's
`bl f; b exit` into a branch to it; writing the same arm as `if (c == 3) { ...; f(0); } else
move = 2; break;` keeps both tails, as the original does.

Found in: src/matched/ov016_func_021CA100.c (0x021CA100, moveFocus in scenesetlist.o)

Cases 11 and 12 both end `drawWindow(); DWCi_SBlSet(k); break;` (k = 0 and 55). The original
keeps two `bl DWCi_SBlSet; b 0x021CA364` tails. With case 11 spelled as an early
`if (dir != 3) { move = 2; break; }` followed by the body, the compiled case 12 ends in
`mov r0, #0x37; b <case 11's bl>`, four bytes short. Case 12 as if/else-if, removing the
`goto end` label and putting the case bodies in other shapes changed nothing; only the
positive if/else in case 11 restored the second tail and closed the function.
