/*
 * function: func_021700C8
 * address:  0x021700C8
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * DWCi_MakeMatchCommandControl: fills a match command block. Same size, 20 bytes
 * differ: a pure register rotation in the 5-byte identifier copy (original puts the
 * pool base in ip, len*4 in r0, 0x5a in r1). See docs/notes/pkt_ov009_021702A0.c.txt.
 *
 * w8_nm tried: `len *= 4` and `len <<= 2` before the header stores, a
 * u8-cast length store: 20 B remain (the object computes len * 4 into r0
 * before loading the id base into ip).
 *
 * w9_nm2: still 20 B. Also tried a u8 local for len * 4 (inside a block),
 * `len *= 4` after the copy, `(unsigned char)(len << 2)`, an idp pointer local
 * for the id copy, and the header stores in six other orders (moving len or
 * command ahead of the id copy changes the prologue, 46 to 54 B). The pool
 * base stays in r0 with len * 4 in r1; the object has ip and r0.
 *
 * symbols:
 *   d_021A2188  0x021A2188  data  a1
 *   MIi_CpuCopy32  0x02082A90  arm
 *   func_02175F3C  0x02175F3C  arm  ov009
 */

typedef struct {
    char id[5];
} MatchId;

typedef struct {
    MatchId id;
    unsigned char pad[3];
    unsigned char command;
    unsigned char len;
    unsigned short port;
    int ip;
    int pid;
    unsigned int data[32];
} MatchCtrl;

extern const MatchId d_021A2188;
extern void MIi_CpuCopy32(const void *src, void *dst, int size);
extern char *func_02175F3C(void);

void func_021700C8(MatchCtrl *ctrl, unsigned char command, const unsigned int *data, int len)
{
    if (data == 0 || len == 0) {
        len = 0;
    } else {
        MIi_CpuCopy32(data, ctrl->data, len * 4);
    }
    ctrl->id = d_021A2188;
    *(int *)((char *)ctrl + 4) = 0x5a;
    ctrl->command = command;
    ctrl->len = len * 4;
    ctrl->port = *(unsigned short *)(func_02175F3C() + 0x5d4);
    ctrl->ip = *(int *)(func_02175F3C() + 0x5d8);
    ctrl->pid = *(int *)(func_02175F3C() + 0x678);
}
