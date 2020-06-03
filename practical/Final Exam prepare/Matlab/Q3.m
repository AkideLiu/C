clc;
clear;
close all;

% Author : Akide Liu 
% Date : 04 / 06 / 2020 
% License and copyright notice: GNU General Public License v3.0 
% https://github.com/AkideLiu/Matlab/blob/master/LICENSE

% Description : This script ...



sequences = input('Enter the sequence: \n','s');

element = input('Which nucleotide do you want to remove?: \n','s');

updated_sequence = remove_nucleotide(sequences,element);

fprintf('Sequences: %s \n', updated_sequence);

count_g = strfind(updated_sequence, 'G');
count_a = strfind(updated_sequence, 'A');
count_c = strfind(updated_sequence, 'C');
count_t = strfind(updated_sequence, 'T');



fprintf('The sequence contains: \n');
fprintf("%d guanine \n", length(count_g));
fprintf("%d adenine \n", length(count_a));
fprintf("%d cytosine \n", length(count_c));
fprintf("%d thymine \n", length(count_t));

function updated_sequence = remove_nucleotide(dna_sequence, nucleotide)

    updated_sequence = erase(dna_sequence, nucleotide);

end