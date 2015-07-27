ls
vi /boot/uEnv.txt 
reboot
ipconfig
ifconfig
mkdir /mnt/boot
mount /dev/mmcblk0p1 /mnt/boot
vi /mnt/boot/uEnv.txt
vi /mnt/boot/nfs-uEnv.txt 
ls
ls
cd ..
ls
cd boot/ls
cd boot/
ls
vi uEnv.txt 
ls /dev/mmcblk0p1
mount /dev/mmcblk0p1 /mnt/boot
cd /opt/scripts/tools/
./update_kernel.sh 
cd ~
ntpdate -b -s -u pool.ntp.org
iwconfig
vi /etc/network/interfaces 
fg
vi /etc/network/interfaces 
vi /etc/network/interfaces 
ifup ra0
vi /etc/network/interfaces 
ifup ra0
ifup ra0
ifdown
ifdown ra0
ifup ra0
ping google.com
cd ~
ls
ntpdate -b -s -u pool.ntp.org
apt-get update && apt-get install git
cd /opt/scripts/tools/
./update_kernel.sh 
reboot
git clone https://github.com/adafruit/wifi-reset.git
cd wifi-reset
chmod +x install.sh
./install.sh
ls
ping google.com
ifdown ra0
ifup ra0
cd ~
ls
mkdir PRU
cd PRU/
git clone https://github.com/rvega/bbb-pru.git
ls
cd bbb-pru/
ls
cd vendors/
ls
git clone https://github.com/rvega/am335x_pru_package.git
ls
cd am335x_pru_package/
ls
git pull 544a20b
git fetch 544a20b
git checkout 544a20b
git status
git diff
cd ..
./install.sh 
ls
cd ..
cd ..
ls
ls
chmod +x ti_cgt_pru_2.0.0B2_armlinuxa8hf_installer.sh 
./ti_cgt_pru_2.0.0B2_armlinuxa8hf_installer.sh 
ls
cd pru_2.0.0B2/
ls
cd ..
ls
rm ti_cgt_pru_2.0.0B2_armlinuxa8hf_installer.sh 
ls
cd 0
vi 0
rm 0
ls
cd bbb-pru/
ls
cd vendors/
ls
cp -r ~/PRU/pru_2.0.0B2/ pru_2.0.0B2/
ls
./install.sh 
ls
ls
cd ..
ls
cd apps/
ls
cd assembler/
ls
make
ls
cd ..
ls
cd gpio/
ls
make
ls
cd .
ls
ls
cd /
ls
cd l
cd lib
ls
cd ..
ls
cd usr/
ls
cd lib/
ls
ls
cd..
ls
cd ~
ls
cd PRU/
ls
cd bbb-pru/
ls
cd apps/
ls
cd gpio/
ls
make
cd ..
ls
cd ..
ls
cd vendors/
ls
./install.sh 
clpru
cd ..
ls
cd apps/
ls
cd gpio/
ls
make
clpru
ls
cd ..
cd ..
ls
cd vendors/
ls
cd pru_2.0.0B2/
ls
cd pru_2.0.0B2/
ls
mv * ../
ls
cd ..
rmdir pru_2.0.0B2/
ls
cd ..
cd ..
ls
cd apps/
ls
cd gpio/
ls
make
ls
./host 
ls
cd .
cd ..
ls
cd assembler/
ls
./host
cd ..
ls
cd ..
ls
cd vendors/
ls
./install.sh 
ls
cd ..
ls
cd apps/
ls
cd gpio/
ls
make
./host 
cd ..
ls
cd assembler/
ls
make
make
cd ..
ls
cd interrupts/
ls
make
cd ..
ls
cd adc
make
make
apt-get install libsndfile1-dev
ls
make
ls
cd ..
ls
cd assembler/
ls
make
cd ..
ls
cd gpio/
make
ls
./host 
reboot
ls
cd PRU/
ls
cd bbb-pru/apps/gpio/
ls
make
./host 
ls
cd ..
cd assembler/
./host 
ls
vi host.c
cd ~
ls
git clone https://github.com/hodduc/vimfile.git
ls
cd vimfile/
ls
mv vimrc ~
ls
cd ..
rmdir vimfile/
rmdir -f vimfile/
rm -rf vimfile/
ls
mv vimrc .vimrc
vi .vimrc
vi .vimrc
vi .vimrc
vi .vimrc
vi .vimrc
vi .vimrc
vi .vimrc
git clone https://github.com/VundleVim/Vundle.vim.git
ls
cd Vundle.vim/
ls
ls
cd ..
rm -rf Vundle.vim/
ls
git clone https://github.com/gmarik/Vundle.vim.git ~/.vim/bundle/Vundle.vim
vi .vimrc
git clone https://github.com/tomasr/molokai
ls
cd molokai/
ls
cd colors/
ls
mv molokai.vim ~/.vim
ls
cd ..
cd ..
ls
rm -rf molokai/
ls
vi .vimrc
cd .vim
ls
vi molokai.vim 
mkdir colors
ls
mv molokai.vim colors
ls
cd ..
ls
vi .vimrc
ls
cd PRU/
ls
cd bbb-pru/
ls
cd vendors/
ls
ls am335x_pru_package/
git status
ls
ls pru_2.0.0B2/
ls
./install.sh 
ls
cd ..
ls
cd apps/
ls
cd gpio/
make
ls
./host 
ls
cd ..
ls
cd ..
ls
cd device-tree-overlay/
ls
make
ls
cd ..
ls
cd apps/
ls
cd gpio/
ls
./host 
make
./host 
ls
cd ..
ls
cd ..
ls
cd vendors/
ls
./install.sh 
ls
cd ..
ls
cd device-tree-overlay/
ls
make
make
ls
vi Makefile 
make install
vi Makefile 
make load
ls
cd ..
ls
cd apps/
ls
cd gpio/
ls
./host
ls
ls
cd .
ls
cd ..
ls
vimdiff gpio/host.c adc/host.c
ls
cd gpio/
ls
vi pru.c
ls
ls
mkdir touchpanel
mv touchpanel/ touchpad
ls
cd touchpad/
ls
vi pru.c
cd ..
mv touchpad/ ..
ls
cd ..
ls
cd ~
ls
vi .bashrc
vi .bashrc
vi .bash_profile
ls
exit
