/*
 * function: func_020315F0
 * address:  0x020315F0
 * packet:   pkt_020315F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *
 * procsys.c: run one step of a process.  State at +8 walks 0 (load the
 * overlay at +4 unless it is -1), 1 (init callback), 2 (main callback),
 * 3 (end callback, then unload the overlay and report finished).  Each
 * callback returns 1 when its phase is done; the sub-sequence counter at
 * +0xC is passed by address and cleared on every phase change.
 */

typedef unsigned int u32;

typedef u32 (*ProcFunc)(void *proc, u32 *seq, u32 pwork, u32 work);

typedef struct {
    ProcFunc init;
    ProcFunc main;
    ProcFunc end;
} ProcData;

typedef struct {
    const ProcData *data;
    u32 ovl;
    u32 seq;
    u32 subseq;
    u32 pwork;
    u32 work;
} Proc;

extern void func_02034AC4(u32 ovl);
extern void func_02034A5C(u32 ovl);

u32 func_020315F0(Proc *p)
{
    switch (p->seq) {
    case 0:
        if (p->ovl != 0xFFFFFFFF) {
            func_02034AC4(p->ovl);
        }
        p->seq = 1;
    case 1:
        if (p->data->init(p, &p->subseq, p->pwork, p->work) == 1) {
            p->seq = 2;
            p->subseq = 0;
        }
        break;
    case 2:
        if (p->data->main(p, &p->subseq, p->pwork, p->work) == 1) {
            p->seq = 3;
            p->subseq = 0;
        }
        break;
    case 3:
        if (p->data->end(p, &p->subseq, p->pwork, p->work) == 1) {
            if (p->ovl != 0xFFFFFFFF) {
                func_02034A5C(p->ovl);
            }
            return 1;
        }
        break;
    }
    return 0;
}
