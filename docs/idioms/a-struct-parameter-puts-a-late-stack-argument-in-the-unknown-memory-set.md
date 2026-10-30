# A struct parameter puts a late stack argument in the unknown-memory set

summary: when a stack argument's load is scheduled one slot too late, and mwccdbg `sched` shows
it ties with another ready node on deadline and height but loses on release count, declaring the
stack arguments as one struct by value in the definition can fix it. The callers keep passing the
arguments one by one: the words on the DS stack are the same.

Found in: src/game/ov093/btlv_scu.c BTLV_SCU_Create (black_ja 0x021EADB0, white_ja the same).

The Japanese image loads heapId (the eighth argument, `ldr r6, [sp, #0x34]`) second; our build
loaded it after the parameter spills. `mwccdbg sched` showed the load and the `lsl` of the
offset constant ready in the same cycle with equal deadline and height; the `lsl` won on release
count because it was the only predecessor of the store of the allocation's line argument.

The rule in tools/mwccdbg/README.md (alias objects of direct field accesses): an access whose
2 * offset + size exceeds its object's size falls into the unknown-memory set G. As a field at
offset 12 of a 16-byte struct, heapId is in G; the line-argument store is in G as well, so the
load becomes a second predecessor of that store, the `lsl` loses its release count, and program
order puts the load first. English Black is byte-identical with either form.

```c
typedef struct {
    void *fontMain;
    void *fontSub;
    u8 clientIndex;
    int heapId;
} BtlvScuStackArgs;

#ifdef __MWERKS__
BtlvScu *BTLV_SCU_Create(struct BtlvCore *core, struct BtlContext *context,
                         struct BtlMonTable *monTable, void *taskSys, BtlvScuStackArgs args)
#else
/* separate arguments, then the struct is filled: a struct by value is another ABI on the PC */
#endif
```

btlv_core.c calls with four separate arguments through its own extern. Building the struct in the
caller adds a 16-byte copy, so the caller keeps the separate form; the mismatch is archived as a
kind D row in docs/ORIGINAL_BUGS.tsv.

Forms that did not work: `*&heapId`, a pointer local to heapId, a local copy, reading heapId
through a cast of `&fontMain` or `&fontSub` (17 bytes off), K&R definitions.
