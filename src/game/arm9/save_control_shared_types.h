#ifndef SAVE_CONTROL_SHARED_TYPES_H
#define SAVE_CONTROL_SHARED_TYPES_H

/*
 * save_control.c: the SaveControl object (the game's save manager) and,
 * after it in the same byte range, three block files that the image keeps
 * adjacent: box_savedata.c (PC boxes), perapvoice.c (Chatot recording) and
 * myitem_savedata.c (the bag).  The cuts are listed in the lane's cuts.tsv.
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

#endif
