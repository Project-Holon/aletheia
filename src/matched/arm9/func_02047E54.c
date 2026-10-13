/*
 * function: G3D_UTIL_Delete
 * address:  0x02047E54
 * packet:   pkt_020477D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0   0x020307B0  arm
 *
 * Free the four pointers of one record, in decreasing address order, and
 * then the record itself.  The object pointer is the only callee-saved
 * value, which is why the frame is two words.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/G3D_UTIL_Delete.c \
 *       --func G3D_UTIL_Delete --addr 0x02047E54 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Rec {
    void *unk_00;
    void *unk_04;
    void *unk_08;
    void *unk_0c;
    void *unk_10;
};

extern u32 func_020307B0(void *p);

void G3D_UTIL_Delete(struct Rec *p)
{
    func_020307B0(p->unk_10);
    func_020307B0(p->unk_0c);
    func_020307B0(p->unk_04);
    func_020307B0(p->unk_00);
    func_020307B0(p);
}
