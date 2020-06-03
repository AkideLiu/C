clc;
clear;
close all;

% Author : Akide Liu 
% Date : 04 / 06 / 2020 
% License and copyright notice: GNU General Public License v3.0 
% https://github.com/AkideLiu/Matlab/blob/master/LICENSE

% Description : This script ...

count = input('How many sequences will you enter? :');

array = strings(1,count);

for i = 1:count
    sequences = input('Enter the sequence: ','s');
    array(i) = sequences;
end


for i = 1:count
    fprintf('Sequences: %s \n', array(i));
end
