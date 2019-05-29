#!/bin/bash

target=$1
CPUperfomance=$(iostat | grep -A1 "avg-cpu:" | tail -n 1 | grep "[0-9]*[\.]*[0-9]*")
RAMinfo=$(free -b | grep "Mem:")
memInfo=$(cat /proc/meminfo | grep "MemTotal:")

retUserCPU() {
    local param=$1
    echo $param
}

retSysCPU() {
    local param=$3
    echo $param
}

retIdleCPU() {
    local param=$6
    echo $param
}

retUsedRAM() {
    local param=$3
    echo $param
}

retMemTotal() {
    local param=$2
    echo $param
}

netFunc() {
    echo ""
}

case "${target}" in
    usercpu)    userCPU $CPUperfomance
                ;;
    syscpu)     sysCPU $CPUperfomance
                ;;
    idlecpu)    idleCPU $CPUperfomance
                ;;
    usedram)    usedRAM $RAMinfo
                ;;
    totalMem)   retMemTotal $memInfo
                ;;
    net)        netFunc 
                ;;
    *)          ;;
esac
