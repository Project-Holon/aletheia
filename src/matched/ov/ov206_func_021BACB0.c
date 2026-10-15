/*
 * function: func_021BACB0
 * address: 0x021BACB0
 * packet: pkt_ov206_021BACB0
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA960 0x021BA960 thumb
 *   func_021BAA08 0x021BAA08 thumb
 *   func_021BAF7C 0x021BAF7C thumb
 *   POKE_PERSONAL_LoadFormTable 0x0201AF80 thumb
 *   func_020307B0 0x020307B0 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   d_021BC110 0x021BC110 data a2
 *   d_021BC11C 0x021BC11C data a2
 */
extern const unsigned short d_021BC110[];
extern const unsigned short d_021BC11C[];
extern void func_021BA960(int heap, int window, void *printer, int font, int input, unsigned short right, unsigned short y, unsigned short color, int alignment, int expansion);
struct MsgBank;
extern void func_021BAA08(int heap, int window, struct MsgBank *bank, void *printer, int font, int message, unsigned short x, unsigned short y, unsigned short color, int alignment, int expansion);
extern void func_021BAF7C(char *);
typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 *POKE_PERSONAL_LoadFormTable(u32 heap, u16 *countOut);
extern u32 func_020307B0(void *p);
struct WordSet;
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);

#define H(o) (*(unsigned short *)(p + (o)))
#define W(o) (*(int *)(p + (o)))

void func_021BACB0(char *p, int idx)
{
    int t0 = W(0x1e0);
    int a30 = ((int *)(p + (idx + 5) * 4))[0x78];
    int a2c = ((int *)(p + (idx + 0xb) * 4))[0x78];
    int a28 = ((int *)(p + (idx + 0x11) * 4))[0x78];
    int a24 = ((int *)(p + (idx + 0x17) * 4))[0x78];
    int a20 = ((int *)(p + (idx + 0x1d) * 4))[0x78];
    unsigned short cur = H(0xc);
    unsigned short c;
    int h;
    int fl;
    unsigned char i;

    if (cur == 0x1e7 && H(0xe) != 0) {
        cur = 0x1ee;
    } else if (cur == 0x1ec && H(0xe) != 0) {
        cur = 0x1ef;
    }
    if (W(0x18) != 2) {
        func_021BAA08(H(0), W(0x6c), (struct MsgBank *)t0, (void *)W(0x2c), W(0x28), 0x90, 0, 5, 0x3c40, 2, 0);
    }
    c = H(0xc);
    if (W(4) == 0) {
        unsigned short *tab = POKE_PERSONAL_LoadFormTable(H(0), 0);
        c = tab[H(0xc)];
        func_020307B0(tab);
    }
    if (c != 0x3e7) {
        h = (int)WORDSET_CreateDefault(H(0));
        if (idx == 0) {
            WORDSET_SetSlotNumber((struct WordSet *)h, 0, c, 3, 2, 0);
        } else {
            WORDSET_SetSlotNumber((struct WordSet *)h, 0, c, 3, 2, 1);
        }
        func_021BA960(H(0), W(0x70), (void *)W(0x2c), W(0x28), W(0x270), 8, 5, 0x440, 0, h);
        WORDSET_DeleteStrbufED04((struct WordSet *)h);
    } else {
        func_021BA960(H(0), W(0x70), (void *)W(0x2c), W(0x28), W(0x274), 8, 5, 0x440, 0, 0);
    }
    c = 0;
    func_021BAA08(H(0), W(0x70), (struct MsgBank *)a20, (void *)W(0x2c), W(0x28), H(0xc), 0x30, 5, 0x440, 0, 0);
    if (W(8) != 0) c = H(0xc);
    func_021BAA08(H(0), W(0x70), (struct MsgBank *)a30, (void *)W(0x2c), W(0x28), c, 0, 0x16, 0x440, 2, 0);
    func_021BA960(H(0), W(0x74), (void *)W(0x2c), W(0x28), ((int *)(p + (idx + 4) * 4))[0x9c], 0, 4, 0x440, 0, 0);
    func_021BA960(H(0), W(0x74), (void *)W(0x2c), W(0x28), ((int *)(p + (idx + 0xa) * 4))[0x9c], 0, 0x14, 0x440, 0, 0);
    c = 0;
    if (W(8) != 0) c = cur;
    func_021BAA08(H(0), W(0x74), (struct MsgBank *)a2c, (void *)W(0x2c), W(0x28), c, d_021BC110[idx], 4, 0x440, 1, 0);
    c = 0;
    if (W(8) != 0) c = cur;
    func_021BAA08(H(0), W(0x74), (struct MsgBank *)a28, (void *)W(0x2c), W(0x28), c, d_021BC11C[idx], 0x14, 0x440, 1, 0);
    c = 0;
    if (W(8) != 0) c = H(0xc);
    func_021BAA08(H(0), W(0x78), (struct MsgBank *)a24, (void *)W(0x2c), W(0x28), c, 4, 5, 0x3c40, 0, 0);
    for (i = 0; i < 4; i++) {
        ((int *)(p + i * 4))[0x1f] = 0;
    }
    func_021BAF7C(p);
}
