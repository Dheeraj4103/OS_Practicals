#!/bin/bash

# let's say for now I have a default address book called address.txt
filename="address.txt"

# function to add records
function add_rec() {
        # first take first name input
        echo "Enter First Name:- "
        read name


        # take mobile number as input
        echo "Enter Mobile Number:- "
        read mobile

        # take city as input
        echo "Enter City:- "
        read city

        echo "$name $mobile $city" >> $filename
        cat $filename
        echo "Record inserted Successful"
}

# function to search a record
function search_rec() {
        echo "Enter the record you want to search:- "
        read rec
        info=$(cat $filename)
        flag=0
        cnt=1
        for i in $info
        do
                if [ $rec == $i ];
                then
                        flag=1
                        echo "Record found at line $((cnt/2))"
                fi
                cnt=$((cnt+1))
        done
        if [ $flag == 0 ];
        then
                echo "Record not found"
        fi
}

#function to delete a record
function delete_rec() {
        echo "Enter the record you want to delete:- "
        read rec
        newfile="new.txt"
        info=$(cat $filename)
                cnt=0
        flag=0
        alltime=0
        temp=""
        for itm in $info;
        do
                if [ $itm == $rec ];
                then
                        alltime=1
                        flag=1
                fi
                temp="$temp $itm"
                cnt=$((cnt+1))

                if [ $((cnt%3)) == 0 ];
                then
                        if [ $flag == 0 ];
                        then
                                echo $temp >> $newfile
                        fi
                        temp=""
                        flag=0
                fi

        done
        if [ $alltime == 0 ];
        then
                echo "Record doesn't exist"
        fi
        mv $newfile $filename
        cat $filename
}

#add_rec

#search_rec

delete_rec
