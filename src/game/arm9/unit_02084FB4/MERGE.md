# unit_02084FB4.c (arm9)

Translation unit 02084FB4..02085A30, 29 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_02084FB4.c` is blocked by:

- func_02084FB4.c..func_02085988.c: type typedef OSThreadQueue differs between members (src/matched/arm9_sdk/OSi_RemoveLinkFromQueue.c); type typedef OSThreadLink differs between members (src/matched/arm9_sdk/OSi_RemoveLinkFromQueue.c);
- func_02084FB4.c..func_02085528.c: type typedef OSThread differs between members (src/matched/arm9_sdk/OSi_RemoveLinkFromQueue.c); type typedef OSThread differs between members (src/matched/arm9_sdk/func_02085078.c); global g_02150FD0 
- func_02084FB4.c..func_02085158.c: type typedef OSThread differs between members (src/matched/arm9_sdk/OSi_RemoveLinkFromQueue.c); type typedef OSThread differs between members (src/matched/arm9_sdk/func_02085078.c); global g_02150FD0 
- OSi_RescheduleThread.c..func_02085528.c: type typedef OSThread differs between members (src/matched/arm9_sdk/func_02085264.c); global g_02150FD0 declared two ways (src/matched/arm9_sdk/func_02085264.c); type typedef OSThread differs between 
- OSi_RescheduleThread.c..func_020853B0.c: type typedef OSThread differs between members (src/matched/arm9_sdk/func_02085264.c); global g_02150FD0 declared two ways (src/matched/arm9_sdk/func_02085264.c)
- func_02085560.c..func_02085988.c: type typedef OSThreadQueue differs between members (src/matched/arm9_sdk/func_020855BC.c); type typedef OSThreadLink differs between members (src/matched/arm9_sdk/func_020855BC.c); type struct OSMutex

Members, in address order:

- `OSi_RescheduleThread.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_02084FB4.c` again.
