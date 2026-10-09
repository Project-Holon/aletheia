# symbol_map.c

Parts that stay separate after the greedy merge (tools in scratchpad ol010), and why:

- Boundaries are prototype conflicts (func_021663F4 takes unsigned char * vs int, struct O vs other layout of the same global in func_021671FC, float vs unsigned int[2] view in p04) and c99=DIFF at func_021672B4. A struct pass must unify the views first.
