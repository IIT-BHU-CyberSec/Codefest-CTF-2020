git clone https://github.com/aunali1/super-strip.git;
cd super-strip;
make;
mv sstrip /usr/bin/;
cd ..;
gcc -s -static picture_shuru.c -o picture_shuru;
sstrip picture_shuru;
