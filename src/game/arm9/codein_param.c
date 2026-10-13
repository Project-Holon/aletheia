/*
 * file:     codein_param.c
 * unit:     yes
 * function: func_0202E4EC, func_0202E54C, func_0202E560, func_0202E610, func_0202E688
 * address:  0x0202E4EC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from time_icon.c at 0x0202E770 (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   func_02030734    0x02030734  arm
 *   func_020457B0    0x020457B0  arm
 *   codein_param_File 0x020A77D0  data
 *   func_02045808  0x02045808  arm
 *   func_020307B0  0x020307B0  arm
 *   g_020A033C     0x020A033C  data
 *   g_020A77E0     0x020A77E0  data
 *   func_02046C94  0x02046C94  arm
 *   func_02046C9C  0x02046C9C  arm
 *   func_02069FD0  0x02069FD0  arm
 *   func_02069FF8  0x02069FF8  arm
 *   func_0206E964  0x0206E964  arm
 *   func_02080C44  0x02080C44  arm
 *   func_02082D44  0x02082D44  arm
 *   g_020A02D0      0x020A02D0  data
 *   GX_GetBankForTex   0x02080C44  arm
 *   GX_SetBankForLCDC  0x0208068C  arm
 *   GX_SetBankForTex   0x02080294  arm
 *   MIi_CpuCopyFast    0x02082B0C  arm
 *   func_02087AE4   0x02087AE4  arm
 *   func_02080B98   0x02080B98  arm
 *   func_02080964   0x02080964  arm
 *   g_020A02B8        0x020A02B8  data
 *   g_020A02C4        0x020A02C4  data
 *   g_020A0300        0x020A0300  data
 *   FX_SinCosTable_   0x020A1B38  data
 *   g_020A2B38        0x020A2B38  data
 *   g_02148B54        0x02148B54  data
 *   g_02148B98        0x02148B98  data
 *   g_02148BCC        0x02148BCC  data
 *   g_02148D8C        0x02148D8C  data
 *   g_02148D98        0x02148D98  data
 *   g_02148DA4        0x02148DA4  data
 *   func_02047A60     0x02047A60  arm
 *   MTX_PerspectiveW  0x0207C408  arm
 *   MTX_LookAt        0x0207BCA0  arm
 *   MTX_RotX33_       0x0207AF00  thumb
 */
struct Strbuf;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int fx32;

typedef signed short s16;

/* Text input parameters (the code-entry screen). */
struct CodeinParam {
    u32 mode;
    u32 maxLength;
    u32 values[4];
    u32 unused;           /* never read; keeps the allocation 0x24 bytes */
    u32 initialPage;
    struct Strbuf *text;
};

/* One entry per display-capture target: LCDC bank mask, capture control
 * bits (shifted into REG_DISPCAPCNT) and the VRAM address of the bank. */
struct CaptureBank {
    u32 lcdcBank;
    u32 captureControl;
    u32 vramAddress;
};

typedef struct {
    fx32 x, y, z;
} VecFx32;

typedef struct {
    fx32 m[9];
} MtxFx33;

/* Camera setup block: six parameter words, then a 3x3 rotation. */
typedef struct {
    u32      params[6];
    MtxFx33  rotation;
} CameraBlock;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Strbuf *func_020457B0(u32 capacity, u16 heapId);
extern void func_02045808(struct Strbuf *str);
extern u32 func_020307B0(void *p);
extern int func_02046C94(void);
extern void func_02082D44(const void *src, void *dst, u32 n);
extern void func_02046C9C(void *control, u32 kind, u32 value);
extern unsigned char *func_0206E964(unsigned char *p);
extern int func_02069FD0(int p);
extern u16 func_02080C44(void);
extern void func_02069FF8(char *p, int a, int b);
extern u32  GX_GetBankForTex(void);
extern void GX_SetBankForLCDC(u32 a);
extern void GX_SetBankForTex(u32 a);
extern void MIi_CpuCopyFast(u32 src, u32 dst, u32 size);
extern void func_02087AE4(void);
extern void func_02080B98(void);
extern int func_02080964(void);
extern void func_02047A60(void *dst, const u32 *params);
extern void MTX_PerspectiveW(fx32 a, fx32 b, fx32 c, fx32 d, fx32 e, fx32 f, void *g);
extern void MTX_LookAt(const VecFx32 *cam, const VecFx32 *tgt,
                       const VecFx32 *up, void *mtx);
extern void MTX_RotX33_(void *mtx, fx32 sinv, fx32 cosv);
struct CodeinParam *func_0202E4EC(u32 heapId, u32 mode, u32 initialPage, u32 maxLength, u32 *values);
void sub_0202E54C(struct CodeinParam *param);
void *func_0202E560(u32 heapId, u32 slotCount);
void func_0202E610(u32 captureIndex, u32 copyIndex);
void func_0202E688(u32 dst);
extern const char codein_param_File[];
extern char g_020A033C[];
extern char g_020A77E0[];
extern struct CaptureBank g_020A02D0[];
extern VecFx32 g_020A02C4;
extern VecFx32 g_020A02B8;
extern CameraBlock g_020A0300;
extern const s16 FX_SinCosTable_[];
extern s16      g_020A2B38[];
extern u32      g_02148B54[];
extern u32      g_02148B98[];
extern u32      g_02148BCC[];
extern VecFx32  g_02148D8C;
extern VecFx32  g_02148D98;
extern VecFx32  g_02148DA4;










/*
 * Levers that decided this one:
 *   - the heap parameter must be u32 with an explicit (u16) cast at each use;
 *     declared u16 the allocator kept the wrong value in r7 and the frame
 *     came out 88 bytes instead of 96.
 *   - `int i;` is declared BEFORE the result pointer, which is what puts the
 *     loop counter in r4 and the result in r5
 *     (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 *   - the struct has a dead u32 at +0x18 between items[4] and w1c, so the
 *     allocator's size argument is 0x24, not 0x20.
 *
 * TU: codein_param.c (__FILE__ 0x020A77D0, line 0x37).
 */
struct CodeinParam *func_0202E4EC(u32 heapId, u32 mode, u32 initialPage, u32 maxLength, u32 *values)
{
    int i;
    struct CodeinParam *param;

    param = func_02030734((u16)heapId, sizeof(struct CodeinParam), 0, codein_param_File, 0x37);
    param->mode = mode;
    param->maxLength = maxLength;
    param->text = func_020457B0(maxLength + 1, (u16)heapId);
    param->initialPage = initialPage;
    for (i = 0; i < 3; i++) {
        param->values[i] = values[i];
    }
    param->values[i] = values[i - 1];

    return param;
}










/*
 * A whole translation unit, matched as one byte range.
 *
 * A destructor: release the one owned handle at offset 0x20, then free
 * the object.
 *
 * Matched as a one-function unit because the two bytes of `00 00` at
 * 0x0202E55E are the linker's inter-section fill before 0x0202E560.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202E54C.c \
 *       --addr 0x0202E54C --thumb
 */
void sub_0202E54C(struct CodeinParam *param)
{
    func_02045808(param->text);
    func_020307B0(param);
}








/*
 * Screen-texture setup (the __FILE__ anchor for this address is
 * screentex.c, 0x020A77E0). Allocates a small control block and a 0x8C-byte
 * work buffer off the heap in a0, seeds the buffer from a template with
 * MI_CpuCopy8 (func_02082D44), binds it to the control block, then builds a
 * packed VRAM descriptor: bits of the bank word returned by func_02080C44
 * are folded into an accumulator under a fall-through switch on a1, and the
 * result is combined with the texture size from func_0206E964 /
 * func_02069FD0 before the final publish through func_02069FF8.
 *
 * BLOCKED: every concrete byte is correct; the single unresolved relocation
 * is the ABS32 to the 0x8C-byte template at 0x020A033C. No evidence class
 * reaches it. The only pool word naming that address anywhere in the image
 * is the one at 0x0202E60C, inside this function's own range, so `literal`
 * and `sole-ref/data` both refuse it (layout/data_objects.txt line for
 * 0x020A033C records exactly that one referrer site, twice-listed from the
 * two unit spellings of the same listing). `tu --suggest-split` confirms no
 * cut exists: 1 witness image wide, 1 of them inside this range. Unsticking
 * this needs a second referrer of 0x020A033C, i.e. another function that
 * loads the same template, to reach EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202E560.c \
 *       --func func_0202E560 --addr 0x0202E560 --cc 1.1p1 --thumb
 */
void *func_0202E560(u32 heapId, u32 slotCount)
{
    void *control;
    void *work;
    void *texHeader;
    u32 texSize;
    u32 vramBanks;
    u32 slotBits;

    control = func_02030734(heapId, func_02046C94(), 0, g_020A77E0, 0x3b);
    work = func_02030734(heapId, 0x8c, 0, g_020A77E0, 0x3c);
    func_02082D44(g_020A033C, work, 0x8c);
    func_02046C9C(control, 2, (u32)work);
    texHeader = func_0206E964(work);
    texSize = func_02069FD0((int)texHeader);
    vramBanks = func_02080C44();
    slotBits = 0;
    switch (slotCount) {
    case 3:
        vramBanks |= 4;
        if (vramBanks) {
            slotBits = slotBits + (4 << 15);
        }
    case 2:
        vramBanks |= 2;
        if (vramBanks) {
            slotBits = slotBits + (2 << 16);
        }
    case 1:
        vramBanks |= 1;
        if (vramBanks) {
            slotBits = slotBits + (1 << 17);
        }
    case 0:
        break;
    }
    func_02069FF8(texHeader, ((texSize >> 4) << 16) | ((slotBits << 13) >> 16), 0);
    return control;
}










/*
 * PARKED AT MATCH.  Every concrete byte is right; the three open sites are
 * the pool words for the 0x020A02D0 table (at +0, +4 and +8), and the only
 * words in the image that hold 0x020A02D0 are this function's own pool at
 * 0x0202E674..0x0202E684, inside the compared range, so `literal` has no
 * outside witness.  It closes the day another function elsewhere in the
 * image loads the same table, or when a shard entry covers one.
 *
 * Bank 0x80300010 is selected for the 12-byte record a0 in 0x020A02D0, its
 * texture slot is remapped to a1's, and a0's frame buffer (0xC000 words per
 * bank, hence the `0xc << 13`) is copied into a1's.  The hardware word at
 * 0x04000064 is a cast constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202E610.c \
 *       --func func_0202E610 --addr 0x0202E610 --cc 1.1p1 --thumb
 */
void func_0202E610(u32 captureIndex, u32 copyIndex)
{
    u32 savedTexBank = GX_GetBankForTex();
    u32 currentTexBank;

    GX_SetBankForLCDC(g_020A02D0[captureIndex].lcdcBank);
    *(u32 *)0x04000064 = (g_020A02D0[captureIndex].captureControl << 16) | 0x80300010;

    func_02087AE4();
    func_02087AE4();
    func_02080B98();
    GX_SetBankForTex(savedTexBank);

    if (captureIndex != copyIndex) {
        currentTexBank = func_02080964();
        MIi_CpuCopyFast(g_020A02D0[captureIndex].vramAddress, g_020A02D0[copyIndex].vramAddress, 0xC << 13);
        func_02080B98();
        GX_SetBankForTex(currentTexBank);
    }
}










static inline s16 FX_SinIdx(int idx)
{
    return FX_SinCosTable_[((idx >> 4) << 1)];
}










static inline s16 FX_CosIdx(int idx)
{
    return FX_SinCosTable_[((idx >> 4) << 1) + 1];
}









static inline void MTX_Perspective(fx32 fovySin, fx32 fovyCos, fx32 aspect,
                                   fx32 n, fx32 f, void *mtx)
{
    MTX_PerspectiveW(fovySin, fovyCos, aspect, n, f, 0x1000, mtx);
}










/*
 * One camera/billboard setup for the texture upload path: three VecFx32
 * globals are snapshotted into locals (0x020A02C4 -> cam, 0x020A02B8 -> tgt,
 * up zeroed between them), a 60-byte render block is copied up from
 * 0x020A0300, the perspective matrix is built with the SDK's
 * MTX_Perspective(FX_SinIdx(0xE38), FX_CosIdx(0xE38), ...) (a 20 degree
 * half-angle; FX_SinCosTable_ at 0x020A1B38), the three vectors are stored back
 * out to 0x02148D8C/0x02148D98/0x02148DA4 and MTX_LookAt writes the view
 * matrix to 0x02148B98.  The two `bics` on word 31 of 0x02148BCC are modes:
 * the first clears 0x50 before the vectors are committed, the second clears
 * 0xe8 after the look-at.  MTX_RotX33_ then writes the 3x3 at +0x18 of the
 * copied block (buf[6]) from the (sin, cos) pair at the head of 0x020A2B38.
 *
 * WAVE 16: the 10-byte residue of docs/notes/pkt_0202E560.c.txt (the cos
 * offset `movs r1, #0xe` issued one slot early) was the SDK inlines.  Written
 * as FX_SinIdx / FX_CosIdx inside the MTX_Perspective inline rather than
 * two constant table reads straight into MTX_PerspectiveW, the argument IR
 * comes out in the image's order.  The old `literal` cap on the four rodata
 * pool words is carried by sole-ref/self now.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202E688.c \
 *       --func func_0202E688 --addr 0x0202E688 --cc 1.1p1 --thumb
 */
void func_0202E688(u32 dst)
{
    VecFx32 cam = g_020A02C4;
    VecFx32 up = { 0, 0, 0 };
    VecFx32 tgt = g_020A02B8;
    CameraBlock block = g_020A0300;

    MTX_Perspective(FX_SinIdx(0xE38), FX_CosIdx(0xE38), 0x1555, 0x1000,
                    0x400000, g_02148B54);
    g_02148BCC[31] &= ~0x50u;
    g_02148D8C = cam;
    g_02148D98 = tgt;
    g_02148DA4 = up;
    MTX_LookAt(&cam, &tgt, &up, g_02148B98);
    g_02148BCC[31] &= ~0xe8u;
    MTX_RotX33_(&block.rotation, g_020A2B38[0], g_020A2B38[1]);
    func_02047A60((void *)dst, block.params);
}
