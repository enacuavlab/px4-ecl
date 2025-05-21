cd ~/Tmp
git clone https://github.com/PX4/PX4-Autopilot.git
(491.46 Mio)
cd PX4-Autopilot/
git checkout v1.15.4

~/Tmp
git clone git@github.com:enacuavlab/px4-ecl.git
(470.63 Kio)

----------------------------------------------
cd px4-ecl
ln -s ../PX4-Autopilot/src/modules/ekf2/EKF
ln -s ../PX4-Autopilot/src/lib/geo 
ln -s ../PX4-Autopilot/src/lib/world_magnetic_model 
ln -s ../PX4-Autopilot/src/lib/mathlib
ln -s ../PX4-Autopilot/src/lib/matrix/matrix
ln -s ../PX4-Autopilot/src/lib/atmosphere 
ln -s ../PX4-Autopilot/src/modules/ekf2/EKF/python/ekf_derivation
ln -s ../PX4-Autopilot/platforms/common/include/px4_platform_common
ln -s ../PX4-Autopilot/Tools
ln -s ../PX4-Autopilot/msg

pip install empy==3.3.4

TODO
./Tools/msg/px_generate_uorb_topic_files.py --headers -f msg/EstimatorAidSource1d.msg -e ./Tools/msg/templates/uorb/msg.h.em -o /home/pprz/Tmp

----------------------------------------------
cp ~/Tmp/px4-ecl/my_custom_patch_file.patch

----------------------------------------------
git clone git@github.com:enacuavlab/paparazzi.git
(132.80 Mio)
cd paparazzi
git checkout opticflow_MTF01 
make

cp conf/airframes/ENAC/conf_enac_vto.xml conf/conf.xml

ln -s ~/Project/paparazzi/sw/ext/ecl  ~/Tmp/px4-ecl

export PAPARAZZI_SRC=/home/pprz/Projects/paparazzi
export PAPARAZZI_HOME=/home/pprz/Projects/paparazzi
make -C /home/pprz/Projects/paparazzi -f Makefile.ac AIRCRAFT=octave_102 clean_ac
make -C /home/pprz/Projects/paparazzi -f Makefile.ac AIRCRAFT=octave_102 ap.compile

----------------------------------------------
cd ~/Tmp/PX4-Autopilot
git diff > ../px4-ecl/my_custom_patch_file.patch
git apply ../px4-ecl/my_custom_patch_file.patch

----------------------------------------------
TODO 
/home/pprz/Projects/paparazzi/sw/ext/ecl/EKF/ekf.h:58:10: fatal error: uORB/topics/estimator_aid_source1d.h: No such file or directory
