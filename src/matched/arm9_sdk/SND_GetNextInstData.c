/*
 * function: SND_GetNextInstData
 * address:  0x0208A48C
 * packet:   pkt_0208A48C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libsnd snd_bank.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Walks a bank's instrument table from *pos: plain instruments return their
 * parameter block, drum sets and key splits return one sub-instrument per
 * call. Returns 1 while an instrument was produced, 0 at the end.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;

typedef struct {
    u16 wave[2];
    u8 original_key;
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
    u8 pan;
} SNDInstParam;

typedef struct {
    u8 type;
    u8 padding_;
    SNDInstParam param;
} SNDInstData;

typedef struct {
    u32 prgNo;
    u32 index;
} SNDInstPos;

typedef struct {
    u8 fileHeader[0x10];
    u8 blockHeader[0x8];
    u8 waveArcLink[0x20];
    u32 instCount;
    u32 instOffset[1];
} SNDBankData;

typedef struct {
    u8 key[8];
    SNDInstData instOffset[1];
} SNDKeySplit;

typedef struct {
    u8 min;
    u8 max;
    SNDInstData instOffset[1];
} SNDDrumSet;

BOOL SND_GetNextInstData(const SNDBankData *bank, SNDInstData *inst, SNDInstPos *pos)
{
    u32 instOffset;
    const SNDDrumSet *drumSet;
    const SNDKeySplit *keySplit;

    for (; pos->prgNo < bank->instCount; pos->prgNo++, pos->index = 0) {
        instOffset = bank->instOffset[pos->prgNo];
        inst->type = (u8)(instOffset & 0xff);
        instOffset >>= 8;

        switch (inst->type) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            inst->param = *(const SNDInstParam *)((const u8 *)bank + instOffset);
            pos->prgNo++;
            return 1;
        case 0x10:
            drumSet = (const SNDDrumSet *)((const u8 *)bank + instOffset);
            for (; pos->index < drumSet->max - drumSet->min + 1; pos->index++) {
                *inst = drumSet->instOffset[pos->index];
                pos->index++;
                return 1;
            }
            break;
        case 0x11:
            keySplit = (const SNDKeySplit *)((const u8 *)bank + instOffset);
            for (; pos->index < 8; pos->index++) {
                if (keySplit->key[pos->index] == 0) {
                    break;
                }
                *inst = keySplit->instOffset[pos->index];
                pos->index++;
                return 1;
            }
            break;
        }
    }
    return 0;
}
