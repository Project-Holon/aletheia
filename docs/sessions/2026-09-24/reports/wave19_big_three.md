# wave 19, lane big_three

Nothing closed.

0x0202CC70 (bgwinfrm.c): DIFF 240/174 -> 244/47, size exact (1.1p1). 25
measurements and one permuter run. What moved it:
1. `sx = win->xmin` written before the ow update in the x clip. x is still
   live there, so sx gets its own slot (sp+0x20) and the size is right.
2. `y = sy; y1 = y + h;` with the clip
   `if (sy < ymin) { sy = ymin; oh -= (s8)(ymin - y); }` on the ties_d w/h
   source. This gives the three live copies of y (57 out).
3. Declarations `s32 sx; s32 w, h; s32 y, sy;` make every spill slot exact
   (47 out).

The residue is an r1/r2 swap between xmax and the y guard's load, and three
small differences follow from it. The permuter (seed 2801, 800) reached 126
out, but only from the earlier 130-out point and through an unsigned compare,
so I discarded it.

0x0200CA98 (musical_dist_save.c): DIFF 147, unchanged. I re-derived the
control flow, and the wave-13 source already matches it block for block, so
the residue is colouring. 12 measurements, including a struct-array rewrite,
inline splits and base-first tails. The permuter (anneal 1500, seed 2811) was
flat.

0x02011688 (ica_anime.c): DIFF 26 -> 14, now with the image's branch
polarity. The source uses `u32 ret = 0; if (p->f18 == n) {...; ret = 1;}
return ret;` with a named `i = idx % n`. The first remainder copy and the
second epilogue are still missing (50 bytes against 56). 12 measurements.

Files: new best-source markers in docs/notes/func_0202CC70.c.txt and
docs/notes/pkt_02011688.c.txt; measurements in
docs/notes/pkt_0200CA98.c.txt. No src/matched files, so no shards verified.
No idioms.

Seeds: none. Integrator: start the next attempt at 0x0202CC70 from the
244/47 source in its note. Nothing committed.
