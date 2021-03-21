git clone https://github.com/aunali1/super-strip.git;
cd super-strip;
make;
mv sstrip /usr/bin/;
cd ../;
gcc -s -masm=intel test.c -o tooeasy;
upx -9 tooeasy
sstrip tooeasy;
