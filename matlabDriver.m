%read in function i.e. driver

%need to take inputs for 
% file name, 
% num words ahead, numiter
% and start word begin


table1 = readtable('transform.csv',"NumHeaderLines", 2, "VariableNamingRule", "preserve");

wordCell = table1.Properties.VariableNames;
numWords = width(table1);
words = strings(numWords);
words(1) = "/n";
for n = 2:numWords
    words(n) = wordCell{n-1};
end
beginWord = "twinkle";
i=0;
startVec = (words==beginWord);
startVec = startVec(:,1);
matrix = transpose(table1{:,:});

output = Bumblebee(matrix, startVec, 10, words, true)






% ask for inputs?// come back to this, only takes list of words and matrix





