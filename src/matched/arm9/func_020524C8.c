/*
 * function: func_020524C8
 * address:  0x020524C8
 * packet:   pkt_02052274
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0205250C  0x0205250C  arm
 *
 * Drain the singly-linked list hanging off p+4: for each node, cache its
 * `next` pointer (the first word) BEFORE handing the node to func_0205250C,
 * which tears the node down.  The cached-next shape is what produces the
 * `ldr r4,[r1]` above the call and the `mov r1,r4; cmp r4,#0` pair below it.
 *
 * Built by the 1.2 front end like the rest of this cluster: the frame pads
 * with `sub sp, sp, #4` and the epilogue is `pop {r4,r5,lr}; bx lr`
 * (docs/idioms/an-armv4t-style-return-and-a-register-blx-name-a-1-2-front-end-not-a-proc-value.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020524C8.c \
 *       --func func_020524C8 --addr 0x020524C8 --cc ../1.2/sp2 --arm \
 *       --flags "-O4,p -proc arm946e"
 */

extern void func_0205250C(char *p, char *q);

void func_020524C8(void *p)
{
    void *n = *(void **)((char *)p + 4);

    while (n != 0) {
        void *next = *(void **)n;
        func_0205250C(p, n);
        n = next;
    }
}
