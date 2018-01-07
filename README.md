# Synth
A basic synth

Control frequency with keyboard
A -> DO
s -> RE
D -> MI
F -> FA
G -> SOL
H -> LA
J -> SI
K -> DO
L -> RE

compile with
gcc main.c -lasound -lpthread -lm `pkg-config --libs allegro-5.0 allegro-5.0 allegro_acodec-5.0 allegro_audio-5.0 allegro_color-5.0 allegro_dialog-5.0 allegro_font-5.0 allegro_image-5.0 allegro_main-5.0 allegro_memfile-5.0 allegro_physfs-5.0 allegro_primitives-5.0 allegro_ttf-5.0`
