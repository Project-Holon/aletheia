/*
 * function: GFL_NET_HANDLE_SendNegotiation
 * address:  0x02039A5C
 * packet:   pkt_02039A5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   GFL_NET_HANDLE_GetNetHandle  0x0203996C  arm
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 *
 * Retire every armed two-byte slot of the own-slot entry: early-out when
 * GFL_NET_SYSTEM_GetCurrentAid() reports busy, otherwise take the 0xFF entry and, for each
 * of the eight slot pairs at +0x2C, clear the +0x2D flag byte once
 * GFL_NET_SendToHandle(entry, 5, 2, &pair) accepts it.
 *
 * THE LAST STORE'S OFFSET IS A NAMED LOCAL, THE OTHER TWO ARE NOT.  Written
 * with `i * 2` spelled at all three uses, the whole function comes out
 * shifted one register up (r5/r6 for entry/index against the image's r4/r5,
 * with an extra callee-saved in the push) and 4 bytes short.  Binding
 * `off = i * 2` at the top of the loop body and using it ONLY at the final
 * `strb` gives that store its own value number: the predicated arm then has
 * to re-materialise the field address as `addne r0, r4, r5, lsl #1` followed
 * by `strbne r6, [r0, #0x2d]`, which is exactly the image's shape, where a
 * shared offset lets the compiler fold 0x2D into a second base register and
 * index off it.  Substituting `off` at the other two uses as well loses it
 * again, and so does declaring `off` inside the loop body rather than beside
 * `p` and `i` (declaration order is stack and colouring order,
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 *
 * Found by tools/permuter.py (mode hill, 148 compiles, mutation
 * `temp(tmp=i * 2)`); the note in docs/notes/pkt_02039A5C.c.txt had ruled out
 * the three hand spellings that keep every offset an expression.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_HANDLE_SendNegotiation.c \
 *       --func GFL_NET_HANDLE_SendNegotiation --addr 0x02039A5C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef unsigned short u16;

typedef signed int     s32;
struct Entry;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern struct Entry *GFL_NET_HANDLE_GetNetHandle(s32 idx);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);

void GFL_NET_HANDLE_SendNegotiation(void)
{
    u8 *p;
    int i;
    int off;

    if (GFL_NET_SYSTEM_GetCurrentAid() != 0) {
        return;
    }
    p = (u8 *)GFL_NET_HANDLE_GetNetHandle(0xff);
    for (i = 0; i < 8; i++) {
        off = i * 2;
        if (*(u8 *)(p + 0x2d + i * 2) != 0) {
            if (GFL_NET_SendToHandle((struct Entry *)p, 5, 2, (u32)(p + 0x2c + i * 2)) != 0) {
                *(u8 *)(p + 0x2d + off) = 0;
            }
        }
    }
}
