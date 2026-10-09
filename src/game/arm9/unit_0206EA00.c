/*
 * file:     unit_0206EA00.c
 * unit:     yes
 * function: func_0206EA00, func_0206EA2C
 * address:  0x0206EA00
 * packet:   pkt_0206EA00
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * NitroSystem g3d binres/res_struct_accessor_anm.c:
 *   0x0206EA00  NNSi_G3dGetTexPatAnmTexNameByIdx
 *   0x0206EA2C  NNSi_G3dGetTexPatAnmPlttNameByIdx
 * NNSG3dResTexPatAnm is {anmHeader, u16 numFrame, u8 numTex, u8 numPltt,
 * u16 ofsTexName, u16 ofsPlttName, ...}; the name arrays are 16-byte
 * NNSG3dResName records.  The library body verbatim (asserts compiled out).
 *
 * Compiler pin, the "kept branches" tell (docs/FRONTEND-PINS.md): the image
 * branches both failed tests to one shared `mov r0, #0; bx lr` tail and
 * keeps the three-instruction success arm unpredicated, 44 bytes; dsi/1.1p1
 * predicates the success arm for 40 bytes whatever the spelling (the
 * wave-4/5 note measured two ifs, &&, ||, nested, result local, goto).
 * The same C is EXACT under ../2.0/sp2 and sp2p2.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct NNSG3dResAnmHeader {
    u8 category0;
    u8 revision;
    u16 category1;
} NNSG3dResAnmHeader;

typedef struct NNSG3dResName {
    char name[16];
} NNSG3dResName;

typedef struct NNSG3dResTexPatAnm {
    NNSG3dResAnmHeader anmHeader;
    u16 numFrame;
    u8 numTex;
    u8 numPltt;
    u16 ofsTexName;
    u16 ofsPlttName;
} NNSG3dResTexPatAnm;

const NNSG3dResName *func_0206EA00(const NNSG3dResTexPatAnm *pPatAnm, u8 texIdx)
{
    if (pPatAnm && texIdx < pPatAnm->numTex) {
        const NNSG3dResName *pNameArray
            = (const NNSG3dResName *)((const u8 *)pPatAnm + pPatAnm->ofsTexName);

        return &pNameArray[texIdx];
    }

    return 0;
}

const NNSG3dResName *func_0206EA2C(const NNSG3dResTexPatAnm *pPatAnm, u8 plttIdx)
{
    if (pPatAnm && plttIdx < pPatAnm->numPltt) {
        const NNSG3dResName *pNameArray
            = (const NNSG3dResName *)((const u8 *)pPatAnm + pPatAnm->ofsPlttName);

        return &pNameArray[plttIdx];
    }

    return 0;
}
