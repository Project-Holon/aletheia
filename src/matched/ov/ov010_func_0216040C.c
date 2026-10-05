/*
 * function: func_0216040C
 * address:  0x0216040C
 * packet:   pkt_ov010_0216040C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled (inside func_0216025C's listing extent): maps a 25-way status
 * code to (kind, detail) at +0xC/+0x10, or to a next state at +0x28
 * (returning 1 for those).
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Req {
    u8 pad[0xC];
    u32 kind;           /* 0x0C */
    u32 detail;         /* 0x10 */
    u8 pad14[0x14];
    u32 next;           /* 0x28 */
} Req;

int func_0216040C(Req *r, u32 code)
{
    switch (code) {
    case 0:
        r->next = 0;
        return 1;
    case 1:
        r->kind = 7;
        return 0;
    case 2:
        r->kind = 11;
        return 0;
    case 3:
        r->kind = 8;
        return 0;
    case 4:
        r->next = 4;
        return 1;
    case 5:
        r->next = 5;
        return 1;
    case 6:
        r->kind = 0;
        r->detail = 5;
        return 0;
    case 7:
        r->kind = 6;
        r->detail = 0;
        return 0;
    case 8:
        r->kind = 6;
        r->detail = 1;
        return 0;
    case 9:
        r->kind = 6;
        r->detail = 2;
        return 0;
    case 10:
        r->kind = 2;
        r->detail = 0;
        return 0;
    case 11:
        r->kind = 2;
        r->detail = 1;
        return 0;
    case 12:
        r->kind = 2;
        r->detail = 2;
        return 0;
    case 13:
        r->kind = 2;
        r->detail = 3;
        return 0;
    case 14:
        r->kind = 2;
        r->detail = 4;
        return 0;
    case 15:
        r->kind = 1;
        r->detail = 1;
        return 0;
    case 16:
        r->kind = 1;
        r->detail = 6;
        return 0;
    case 17:
        r->kind = 1;
        r->detail = 2;
        return 0;
    case 18:
        r->kind = 1;
        r->detail = 3;
        return 0;
    case 19:
        r->kind = 1;
        r->detail = 4;
        return 0;
    case 20:
        r->kind = 1;
        r->detail = 5;
        return 0;
    case 21:
        r->kind = 3;
        r->detail = 1;
        return 0;
    case 22:
        r->kind = 3;
        r->detail = 2;
        return 0;
    case 23:
        r->kind = 3;
        r->detail = 3;
        return 0;
    case 24:
        r->kind = 5;
        return 0;
    }
    r->kind = 1;
    return 0;
}
