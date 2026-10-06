/*
 * file:     unit_02069D14_p01.c
 * unit:     yes
 * function: func_02069D14, func_02069D68
 * address:  0x02069D14
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
 *   g_020A8234     0x020A8234  data
 *   g_020A8238     0x020A8238  data
 *   g_020A823C     0x020A823C  data
 *   func_02082A7C  0x02082A7C  arm
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct {
    u8  pad00[4];
    u32 f04;
    u8  pad08[4];
    u32 f0c;
    u8  pad10[4];
    u32 f14;
    u8  pad18[4];
    u32 f1c;
} S;

typedef struct Node {
    u8 unk00[0x10];
    struct Node *next;
    u8 unk14[4];
    u8 pri18;
} Node;

extern void func_02082A7C(u32 val, void *dst, u32 len);
void func_02069D14(S *p, u32 b);
void func_02069D68(Node **head, Node *item);
extern u32 g_020A8234;
extern u32 g_020A8238;
extern u32 g_020A823C;


/*
 * cap:      literal - 0x020A823C (data) has no witness outside 0x02069D14..0x02069D68;
 *           the second pool word of the same word-run (0x020A8238 / 0x020A8234)
 *           resolves as data_table, this one occurs only inside the compared range.
 *           All 17 instructions and the two other pool words are byte-identical.
 */
void func_02069D14(S *p, u32 b)
{
    func_02082A7C(0, p, 0x54);
    p->f0c = g_020A823C;
    p->f14 = g_020A8238;
    p->f1c = g_020A8234;
    p->f04 = b;
}


/*
 * Priority-ordered insert into the singly-linked list rooted at *head. The
 * list links through +0x10 and orders on the unsigned byte at +0x18, highest
 * first; `item` may itself already be a chain, so before splicing it in the
 * code walks to its own tail and attaches the displaced remainder there.
 *
 * Three shape notes:
 *  - The one-element case (*head has no next) is written out separately from
 *    the general search; that is what produces the `bne`/`beq` pair on one
 *    `cmp r2,#0` at +0x18 and +0x60, where the second branch re-uses the
 *    flags the first one set.
 *  - The search loop is TOP-TESTED (`while (nx != 0)` with the priority test
 *    inside). Rotating it into `while (nx->pri18 >= ...)` with a NULL check at
 *    the bottom compiles to 188 bytes, four too many.
 *  - The insert guard is `nx->pri18 >= item->pri18`; the reverse polarity is
 *    a single wrong byte at +0x70 (`bhs` for `blo`), the only difference
 *    between the two spellings.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02069D68.c \
 *       --func func_02069D68 --addr 0x02069D68 --cc 1.1p1 --arm
 */
void func_02069D68(Node **head, Node *item)
{
    Node *cur;
    Node *nx;
    Node *tail;

    cur = *head;
    if (cur == 0) { *head = item; return; }
    nx = cur->next;
    if (nx == 0) {
        if (cur->pri18 > item->pri18) {
            tail = item;
            if (item->next != 0) {
                do {
                    tail = tail->next;
                } while (tail->next != 0);
            }
            tail->next = cur;
            *head = item;
            return;
        }
        cur->next = item;
        return;
    }
    while (nx != 0) {
        if (nx->pri18 >= item->pri18) {
            tail = item;
            if (item->next != 0) {
                do {
                    tail = tail->next;
                } while (tail->next != 0);
            }
            cur->next = item;
            tail->next = nx;
            return;
        }
        cur = nx;
        nx = nx->next;
    }
    cur->next = item;
}
