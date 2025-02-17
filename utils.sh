#!/bin/bash

function build_docker()
{
    docker build -t coffee_shop .
}

function enter_docker_env()
{
    docker run -it --security-opt apparmor=unconfined --cap-add=sys_nice \
        --volume="/etc/group:/etc/group:ro" \
        --pid=host \
        --volume="/tmp/.X11-unix:/tmp/.X11-unix" \
        --volume="/etc/sssd/:/etc/sssd/" \
        --volume="/home/juanan/git/coffeeShop/:/opt/coffeeShop/:rw" \
        --network host coffee_shop \
        bash 
}

function build_program()
{
    if [ ! -d "build" ]; then
        mkdir build
    fi

    cmake -Bbuild -H. 
    cmake --build build    
}

function execute_program(){
    /opt/coffeeShop/build/coffee_shop
}

function execute_tests(){
    /opt/coffeeShop/build/test/coffee_shop_test
}