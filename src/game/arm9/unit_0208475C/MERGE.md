# unit_0208475C.c (arm9)

Two parts remain: `unit_0208475C_p01.c` (0208475C..) and `unit_0208475C_p02.c` (OSi_EnterTimerCallback onward).
Merging them gives c99=DIFF: most likely code between the two parts has no verified match yet (a gap), so the
merged file lays the second part at the wrong address. Merge when the gap function is matched.
Done in this pass: duplicate static inline helpers (OS_DisableIrq, OS_RestoreIrq) kept once.

- `OSi_EnterNDmaCallback.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.
