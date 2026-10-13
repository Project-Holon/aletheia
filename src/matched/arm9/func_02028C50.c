/*
 * unit:     no
 * function: FIELD_SOUND_SYSTEM_IsSoundRecordChainValid
 * address:  0x02028C50
 * packet:   pkt_02028C50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   NNS_SndArcGetSeqInfo  0x02074324  arm
 *   NNS_SndArcGetFileAddress  0x0207466C  arm
 *   NNS_SndArcGetBankInfo  0x020743EC  arm
 *   NNS_SndArcGetWaveArcInfo  0x02074450  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct EntryA {
    u32 f00;
    u16 f04;
};

struct EntryB {
    u32 f00;
    u16 f04[4];
};

struct EntryC {
    u32 f00 : 24;
};

extern void *NNS_SndArcGetSeqInfo(int index);
extern u32 NNS_SndArcGetFileAddress(u32 idx);
extern void *NNS_SndArcGetBankInfo(int index);
extern struct EntryC *NNS_SndArcGetWaveArcInfo(u32 id);

u32 FIELD_SOUND_SYSTEM_IsSoundRecordChainValid(int index)
{
    struct EntryA *a;
    int i;
    struct EntryB *b;

    a = NNS_SndArcGetSeqInfo(index);
    if (NNS_SndArcGetFileAddress(a->f00) == 0) {
        return 0;
    }

    b = NNS_SndArcGetBankInfo(a->f04);
    if (NNS_SndArcGetFileAddress(b->f00) == 0) {
        return 0;
    }

    for (i = 0; i < 4; i++) {
        if (b->f04[i] != 0xffff) {
            if (NNS_SndArcGetFileAddress(NNS_SndArcGetWaveArcInfo(b->f04[i])->f00) == 0) {
                return 0;
            }
        }
    }

    return 1;
}
