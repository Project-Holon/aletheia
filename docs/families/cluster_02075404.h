/*
 * docs/families/cluster_02075404.h -- shared declarations for the
 * pseudo-family at 0x02075404..0x02075890 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file.
 *
 * WHAT IT IS.  Resource-slot binding on top of the archive loader of
 * docs/families/cluster_020737C0.h (subsystem B): walk an archive's slots or
 * sequence records and bind each to a sound/handle object through the
 * 0x02072Dxx / 0x02073xxx layer.
 *
 *   func_02075404  walk a sequence's records, bind kind-1 records    sp2 EXACT
 *   func_020754C4  walk the 32 archive slots, apply + register        sp2 EXACT
 *   func_02075560  record -> func_02075698 with the record's bytes    1.1p1
 *   func_020755A8  same, caller-overridable (<0 = take the record's)  1.1p1
 *   func_02075618  record -> func_02075794                            1.1p1
 *   func_02075698  open/bind slot (kind 6) + block (kind 1)/attach    sp2 EXACT
 *   func_02075794  its sibling, block from the caller                 sp2 EXACT
 *
 * COMPILER.  The walkers and binders are ../2.0/sp2; the thin record
 * wrappers are dsi/1.1p1.  ISA: ARM.
 */
#ifndef CLUSTER_02075404_H
#define CLUSTER_02075404_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

/* The slot record func_020744B4 returns (func_020754C4). */
typedef struct {
    u8    count;               /* 0x00  ldrb, compared signed with the loop   */
    u8    pad01;
    u16   h2;                  /* 0x02  applied with func_02072DD0            */
    void *data;                /* 0x04  registered count times                */
} SlotRec;

/* The slot index is `int` in the loop AND in the callee prototypes: with
   func_02072DE8's first parameter declared u32 the implicit conversion
   reshuffles r4-r7 in func_020754C4 (14 bytes).                            */
extern void    *func_020742FC(void);
extern SlotRec *func_020744B4(int index);
extern void     func_02072DB0(int idx, int v);
extern void     func_02072DD0(int idx, u32 val);
extern u32      func_02072DE8(int idx, u32 a, void *src);

extern void *func_02073344(u32 a0, u32 a1, u32 a2);    /* open handle        */
extern u32   func_020734AC(u32 a, void *h);
extern u32   func_02074CD0(u32 a, u32 kind, u32 v, u32 d, u32 *out);
extern u32   func_02074BEC(u32 id, u32 kind, u32 v, u32 d, u8 **out);
extern void  func_020733DC(void *h);                   /* release handle     */
extern void  func_020733E8(void *h, u32 *payload, u32 b, u32 slot);
extern void  func_02072F48(u32 a, u32 b);
extern void  func_02072F88(u32 a, u32 b);
extern void  func_020730B8(u32 a, u32 b);

/* s0 = the record pointer (bytes 6 and 7 applied), s1 = the record id.    */
extern u32 func_02075698(u32 a0, u32 a1, u32 a2, u32 a3, u8 *s0, u32 s1);
extern u32 func_020754C4(u32 a);

#endif /* CLUSTER_02075404_H */
