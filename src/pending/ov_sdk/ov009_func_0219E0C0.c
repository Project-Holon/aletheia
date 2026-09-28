/*
 * function: SBServerGetStringValueA
 * address:  0x0219E0C0
 * packet:   pkt_ov009_0219E0C0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      SBServerGetStringValueA (sb_server.o)
 *
 * BLOCKER (codegen, 4 bytes short): the original returns the def pointer from
 * the shared tail at 0x0219E108 (mov r0, r5 / pop), while mwcc emits the
 * default value as a second conditional-pop epilogue (`addne sp,#8; movne r0,r4;
 * popne`) and places a duplicate `mov r0, r5; pop` tail after it.  Both value
 * paths and all branch targets are otherwise right.  Residue: +0030 beq target,
 * and +0044.. the duplicated epilogue.  None of the tried spellings (bare
 * if(ptr), nested if, named value local, `ptr != 0 && strlen(...)` guard) move
 * the return into one shared block.
 *
 * symbols:
 *   TableLookup   0x0218482C  arm
 *   strlen        0x0209477C  arm
 */

struct HashImplementation;
struct _SBServer {
    char pad[0x18];
    struct HashImplementation *keys;
};
struct _SBKeyValuePair {
    char *key;
    char *value;
};

extern void *TableLookup(struct HashImplementation *table, void *elemKey);
extern unsigned int strlen(char *s);

char *SBServerGetStringValueA(struct _SBServer *server, char *keyname,
                              char *def)
{
    struct _SBKeyValuePair *ptr;
    struct _SBKeyValuePair kv;
    char *value;

    if (server == 0)
        return 0;
    kv.key = keyname;
    ptr = TableLookup(server->keys, &kv);
    if (ptr != 0)
    {
        value = ptr->value;
        if (strlen(value) != 0)
            return value;
    }
    return def;
}
