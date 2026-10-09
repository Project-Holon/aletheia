/*
 * file:     unit_02061B2C_p02.c
 * unit:     yes
 * function: func_02061C44, sub_02061CA4, func_02061D0C, func_02061DF0, func_02061DFC, func_02061E48, DWCi_TSKlForm
 * address:  0x02061C44
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02146B80  0x02146B80  data
 *   func_02061BB0  0x02061BB0  arm
 *   func_02061BD0  0x02061BD0  arm
 *   func_02061B2C  0x02061B2C  arm
 *   func_02061860  0x02061860  arm
 *   func_02061BC0  0x02061BC0  arm
 *   func_02061B74  0x02061B74  arm
 *   func_02061EB8 0x02061EB8 arm
 */
struct Obj02061BD0;
struct Blk;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef signed int    s32;

struct Req {
    void *unk_00;
    u32 unk_04;
    u32 unk_08;
    s32 size;   /* 0x0c, byte size consumed */
};

struct Queue {
    u8 pad_00[0x10];
    s32 total;  /* 0x10, running byte total */
};

struct Node {
    u32 start;
    u32 size;
    struct Node *prev;
    struct Node *next;
};

struct Range {
    u32 start;
    u32 end;
};

typedef unsigned short u16;

struct Node02061DFC {
    u32 data0;                 /* 0x0 */
    u32 data1;                 /* 0x4 */
    struct Node02061DFC *prev; /* 0x8 */
    struct Node02061DFC *next; /* 0xc */
};

struct Node02061E48 {
    u32 data0;                 /* 0x0 */
    u32 data1;                 /* 0x4 */
    struct Node02061E48 *prev; /* 0x8 */
    struct Node02061E48 *next; /* 0xc */
};

struct Pool02061E48 {
    struct Node02061E48 *free_list;
};

struct List02061E48 {
    struct Node02061E48 *head;
};

extern u32 func_02061BB0(u8 *p);
extern u32 func_02061BD0(struct Obj02061BD0 *p);
extern void func_02061B2C(u32 *s);
extern int func_02061860(u8 *p);
extern u32 func_02061BC0(u8 *p);
extern int func_02061B74(char *p);
extern int func_02061EB8(struct Blk **list, struct Blk **pool, u32 *pRet, u32 size, u32 alignment);
void func_02061C44(void);
s32 sub_02061CA4(void *p, u32 a, u32 b, s32 size);
u32 func_02061D0C(struct Node **head1, struct Node **head2, struct Range *range);
void NHTTPi_InitRequestInfo(u32 *reqInfo_p);
struct Node02061DFC *func_02061DFC(struct Node02061DFC *arr, u32 count);
u32 func_02061E48(struct List02061E48 *list, struct Pool02061E48 *pool, u32 d0, u32 d1);
asm void DWCi_TSKlForm(void);
extern struct Queue g_02146B80;


/*
 * Drain loop over the 0x02146B80 work record: fetch the head node, pump the
 * record's one-step state machine, and for as long as it reports progress
 * dispose of the node and subtract its size field from the record's running
 * byte total at +0x10, then fetch the next head.
 *
 * Blocked at MATCH on the `matched` class: func_02061B2C (PC24 at +0x0028)
 * and func_02061BD0 (PC24 at +0x0018 and +0x004c) each have their only
 * branch inside 0x02061C44..0x02061CA0, so both sites stay wildcarded.  Both
 * callees are documented dead ends in docs/notes/pkt_02061B2C.c.txt and
 * docs/notes/pkt_02061BD0.c.txt (16 and 6 concrete bytes of instruction
 * selection residue respectively), so neither can ever be filed EXACT and
 * neither can attest this file.  Every concrete byte here reproduces.
 */
void func_02061C44(void)
{
    struct Req *n = (struct Req *)func_02061BB0((u8 *)(&g_02146B80));

    while (func_02061BD0((struct Obj02061BD0 *)(&g_02146B80)) != 0) {
        func_02061B2C((u32 *)n);
        g_02146B80.total -= n->size;
        n = (struct Req *)func_02061BB0((u8 *)(&g_02146B80));
    }
}




/*
 * Pushes one four-word request onto the queue object at 0x02146B80 and adds
 * its size field to the queue's running byte total at +0x10. func_02061860
 * is the "queue full" test: a non-zero answer makes this return 0 without
 * touching anything, which is why the failure path is a `movne r0, #0` fused
 * into the conditional epilogue rather than a branch.
 *
 * The middle two stores land as one `stmib r4, {r7, r8}` and that ordering is
 * the whole tell for the argument mapping: `stm` writes the lowest-numbered
 * register to the lowest address, so +4 takes r7 (the third argument) and +8
 * takes r8 (the second). Writing the two fields in numeric field order
 * instead swaps the two arguments and still produces an `stmib`, so the
 * verdict stays SIZE-clean and the diff is only two bytes.
 *
 * This was capped at MATCH until 0x02061B74, the queue push, was matched in
 * src/matched/func_02061B74.c; that entry is the witness the `bl` needed.
 * func_02061BC0 is likewise a matched entry now.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02061CA4.c \
 *       --func sub_02061CA4 --addr 0x02061CA4 --cc 1.1p1 --arm
 */
s32 sub_02061CA4(void *p, u32 a, u32 b, s32 size)
{
    struct Req *req;

    if (func_02061860((u8 *)(&g_02146B80)) != 0) {
        return 0;
    }

    req = (struct Req *)func_02061BC0((u8 *)(&g_02146B80));
    req->unk_00 = p;
    req->unk_04 = b;
    req->unk_08 = a;
    req->size = size;
    func_02061B74((char *)(&g_02146B80));
    g_02146B80.total += req->size;
    return 1;
}





u32 func_02061D0C(struct Node **head1, struct Node **head2, struct Range *range) {
    struct Node *curr = *head1;
    struct Node *next_node;
    u32 ret = 0;
    u32 zero1 = ret;
    u32 zero2 = ret;

    if (curr != 0) {
        while (curr != 0) {
            next_node = curr->next;

            if (curr->start == range->end) {
                struct Node *next;
                struct Node *prev;
                struct Node *head2_curr;

                range->end = curr->start + curr->size;
                ret |= 1;

                prev = curr->prev;
                next = curr->next;
                if (prev != 0) {
                    prev->next = next;
                } else {
                    *head1 = next;
                }
                if (next != 0) {
                    next->prev = prev;
                }

                head2_curr = *head2;
                if (head2_curr != 0) {
                    head2_curr->prev = curr;
                }
                curr->next = *head2;
                curr->prev = (struct Node *)zero1;
                *head2 = curr;
            }

            if (range->start == curr->start + curr->size) {
                struct Node *next;
                struct Node *prev;
                struct Node *head2_curr;

                range->start = curr->start;
                ret |= 1;

                prev = curr->prev;
                next = curr->next;
                if (prev != 0) {
                    prev->next = next;
                } else {
                    *head1 = next;
                }
                if (next != 0) {
                    next->prev = prev;
                }

                head2_curr = *head2;
                if (head2_curr != 0) {
                    head2_curr->prev = curr;
                }
                curr->next = *head2;
                curr->prev = (struct Node *)zero2;
                *head2 = curr;
            }

            curr = next_node;
        }
    }

    return ret;
}





void NHTTPi_InitRequestInfo(u32 *reqInfo_p)
{
    *reqInfo_p = 0;
}





/*
 * note:     closed 2026-09-21 by tools/permuter.py (hill, --types, ret-var): the function
 *           returns the array pointer it was given; the void version freed r0 too early (2 bytes)
 */
struct Node02061DFC *func_02061DFC(struct Node02061DFC *arr, u32 count)
{
    u32 last = count - 1;
    u32 i = 0;
    u32 *end;

    if (last != 0) {
        struct Node02061DFC *p = arr;
        do {
            struct Node02061DFC *next_node = &arr[i + 1];
            arr[i].next = next_node;
            (&arr[i])[1].prev = p;
            i++;
            p++;
        } while (i < last);
    }

    arr[0].prev = 0;
    end = (u32 *)&arr[count];
    end[-1] = 0;
    return arr;
}





u32 func_02061E48(struct List02061E48 *list, struct Pool02061E48 *pool, u32 d0, u32 d1)
{
    struct Node02061E48 *node = pool->free_list;

    if (node != 0) {
        pool->free_list = node->next;
    }

    if (node == 0) {
        goto err;
    }

    node->data0 = d0;
    node->data1 = d1;
    node->prev = 0;
    node->next = 0;

    if (list->head != 0) {
        list->head->prev = node;
    }

    node->next = list->head;
    node->prev = 0;
    list->head = node;

    return 1;

err:
    return 0;
}


asm void DWCi_TSKlForm(void)
{
    stmfd sp!, {r3, lr}
    mov ip, #0
    str ip, [sp]
    bl func_02061EB8
    ldmfd sp!, {r3, pc}
}
