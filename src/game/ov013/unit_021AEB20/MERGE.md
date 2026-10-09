# unit_021AEB20 (ov013)

Reduced from 9 parts plus 10 folder members to 12 parts. Left: global d_021B3C80, d_021B3C84, d_021B3CB0, d_021B3CBC declared with different local struct views; struct Work and Node defined differently in p03..p06; p07+p08 differ in code. Need one unified struct per global (offsets must be compared first).

Round 4 (r4_ov05): p07|p08 is a Thumb to ARM change (p01..p07 thumb, p08..p12 arm), a real file boundary. Greedy pass again: p01..p07 and p08..p12 each stop on struct clashes (Node as unsigned int against struct Node, Work defined differently in p04..p06 and p07, anonymous struct views in p09..p12). tools-side unifier (unif41) only unified Work in p04 and p06 and p06 then lost u16; not applied.
