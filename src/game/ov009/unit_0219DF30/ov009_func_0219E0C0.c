/*
 * function: func_0219E0C0
 * address:  0x0219E0C0
 * packet:   pkt_ov009_0219E0C0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SBServerGetStringValueA (sb_server.o)
 *
 * Closed (w5_nm): one guard `if (ptr == 0 || strlen(ptr->value) == 0) return def;`
 * followed by `return ptr->value;`, with strlen from string.h so the value stays
 * in r4 across the call. The positive-test order duplicated the epilogue.
 *
 * symbols:
 *   TableLookup                    0x0218482C  arm ov009
 *   strlen                         0x0209477C  arm
 */

#include "../../../matched/arm9_sdk/libc/string.h"

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

char *func_0219E0C0(struct _SBServer *server, char *keyname, char *def)
{
    struct _SBKeyValuePair *ptr;
    struct _SBKeyValuePair kv;

    if (server == 0)
        return 0;
    kv.key = keyname;
    ptr = TableLookup(server->keys, &kv);
    if (ptr == 0 || strlen(ptr->value) == 0)
        return def;
    return ptr->value;
}
