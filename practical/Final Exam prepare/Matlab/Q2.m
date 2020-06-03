clc;
clear;
close all;

% Author : Akide Liu 
% Date : 04 / 06 / 2020 
% License and copyright notice: GNU General Public License v3.0 
% https://github.com/AkideLiu/Matlab/blob/master/LICENSE

% Description : This script ...

sequences = input('Enter the sequence: ','s');

fprintf('Sequences: %s \n', sequences);

count_g = strfind(sequences, 'G');
count_a = strfind(sequences, 'A');
count_c = strfind(sequences, 'C');
count_t = strfind(sequences, 'T');

fprintf('The sequence contains: \n');
fprintf("%d guanine \n", length(count_g));
fprintf("%d adenine \n", length(count_a));
fprintf("%d cytosine \n", length(count_c));
fprintf("%d thymine \n", length(count_t));

