/*
 * docs/families/screentex.h -- the screentex.c family, 0x0202E54C..0x0202E770
 * in the ARM9 image (func_0202E560, func_0202E610, unit_0202E54C and, from
 * wave 16, func_0202E688; all EXACT, family closed).
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file.
 *
 * The family renders a texture through the 3D engine with its own camera:
 * func_0202E688 snapshots three VecFx32 constants into locals, copies a
 * 60-byte render block (a struct assignment, the ldm/stm loop), builds the
 * projection with the SDK's MTX_Perspective(FX_SinIdx(i), FX_CosIdx(i), ...)
 * and the view with MTX_LookAt, and hands the block to func_02047A60.
 *
 * LEVER: SDK inline shapes.  Two constant reads of FX_SinCosTable_ passed
 * straight to MTX_PerspectiveW compile one offset materialisation late; the
 * FX_SinIdx / FX_CosIdx inlines inside the MTX_Perspective inline (which
 * supplies FX32_ONE as the sixth argument) reproduce the image.  NitroSDK's
 * definitions, which this tree does not ship:
 *
 *   static inline s16 FX_SinIdx(int idx)
 *   { return FX_SinCosTable_[((idx >> 4) << 1)]; }
 *   static inline s16 FX_CosIdx(int idx)
 *   { return FX_SinCosTable_[((idx >> 4) << 1) + 1]; }
 *   static inline void MTX_Perspective(fx32 s, fx32 c, fx32 aspect,
 *                                      fx32 n, fx32 f, MtxFx44 *mtx)
 *   { MTX_PerspectiveW(s, c, aspect, n, f, FX32_ONE, mtx); }
 *
 * FX_SinCosTable_ is 0x020A1B38 (sin/cos s16 pairs); MTX_PerspectiveW
 * 0x0207C408, MTX_LookAt 0x0207BCA0 (arm), MTX_RotX33_ 0x0207AF00 (thumb).
 */
