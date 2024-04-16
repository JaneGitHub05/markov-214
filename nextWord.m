%% Algorithm to predict the next word based on previous

%%input: probability matrix "wordMat" (given one word), vector "wordVec" IDing specific word

function nW = nextWord(wordMat, wordVec)
    wordProb = wordMat*wordVec;
    nW = {wordProb, find(wordProb == max(wordProb))};
end
