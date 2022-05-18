import React, { useEffect, useState, useRef } from 'react';
import {
    Col, Row, Container, Form, FormGroup, Card, CardHeader, CardBody, Collapse, Input
} from 'reactstrap'
import RequireAuth from '../Auth/RequireAuth';
import CommonDropdown from '../common/CommonDropdown';
import { Tune } from '@material-ui/icons';
import { Select, MenuItem } from '@material-ui/core/Menu';
import { AjaxLoader } from '../common/AjaxLoader';
import { AgGridReact } from 'ag-grid-react';
import 'ag-grid-community';
import 'ag-grid-community/dist/styles/ag-grid.css';
import 'ag-grid-community/dist/styles/ag-theme-alpine.css';
import 'ag-grid-autocomplete-editor/main.css';
import '../../css/Standard.css';
import StartStopIcon from './StartStopIcon';
import { connect } from 'react-redux';
import FundFilter from '../common/FundFilter';
import PrimaryButton from '../common/button/PrimaryButton';
import clsx from 'clsx';
import { cloneDeep, isNull } from 'lodash';
import { FontAwesomeIcon } from '@fontawesome/react-fontawesome';
import { faArrowDown, faArrowUp } from '@fontawesome/free-solid-svg-icons';
import { getJobProcess, getJobInfo } from '../../actions/JobNotificationAction';
import DateTimePicker from '../common/DateTimePicker';
import { MessageTypes, GeneralPermID, JobProcessExecutionStatus } from '../../common/commonEnums';
import MessageModalPopup from '../common/MessageModalPopup';
import AccessDenied from '../common/AccessDenied';
import { getPermission } from "../../common/Global";
import { hideNotification } from "../../actions/ActivityActions";
import { jobSwitchActionTypes, jobNotificationActionTypes } from "../../actions/ActionTypes";
import "../../css/SearchFilter.scss";
import AntSelect from '../common/AntComponent/Select/AntSelect';

var searchFields = [];
searchFields.push({ key: 'Name', value: 'Investor Name' });
searchFields.push({ key: 'Number', value: 'Investor #' });
searchFields.push({ key: 'ID', value: 'Investor ID' });

const FailedJobNotificationDashboard = ({ jobProcessCollection, fundCollection, clientCollection, jobCollection, isLoading,
    updateSuccess, updateMessage, fetchSuccess, fetchMessage, loginName, wireStatusDetail,
    getJobprocess, setJobProcess, getJobInfo, hideNotification }) => {
    const [isFilterOpen, setIsFilterOpen] = useState(true);
    const [fundFilterError, setFundFilterError] = useState('');
    const [selectedClients, setSelectedClients] = useState([]);
    const [selectedFunds, setSelectedFunds] = useState([]);
    const [selectedJobs, setSelectedJobs] = useState({ jobId: -1, jobName: 'Select Job' });
    const [selectedStatus, setSelectedStatus] = useState({ id: 0, jobStatus: 0, statusName: 'Pending' });
    const [fromDate, setFromDate] = useState();
    const [validateFromDate, setValidateFromDate] = useState('');
    const [activityNo, setActivityNo] = useState('');
    const [validateActivityNo, setValidateActivityNo] = useState('');
    const [reasonText, setReasonText] = useState('');
    const [validateRows, setValidateRows] = useState('');
    const [validateReason, setValidateReason] = useState('');
    const [investorFilter, setInvestorFilter] = useState('Investor Name');
    const [investorText, setInvestorText] = useState('');
    const [showClearButton, setShowClearButton] = useState(false);
    const [gridApi, setgridApi] = useState(null);
    const [statusCollection, setStatusCollection] = useState(() => { return [{ id: 0, jobStatus: JobProcessExecutionStatus.Pending, statusName: 'Pending' }, { id: 1, jobStatus: JobProcessExecutionStatus.Failed, statusName: 'Failed' }, { id: 2, jobStatus: JobProcessExecutionStatus.Success, statusName: 'Success' }] });

    useEffect(() => {
        var data = {
            date: null,
            clientIDs: -1,
            fundIDs: -1,
            activityDataID: -1,
            investorID: null,
            investorNo: null,
            investorName: null,
            jobId: -1,
            status: selectedStatus.jobStatus,
            reportlevel: null
        };
        getJobProcess(data);
        getJobInfo();
    }, []);

    const onToggle = () => {
        setIsFilterOpen(!isFilterOpen);
    };

    const handleFundFilter = (errorMessage) => {
        setFundFilterError(errorMessage);
    }

    const getSearchFieldValueBykey = (key) => {
        var result = searchFields.filter((field) => {
            return field.key == key;
        });
        if (result != null) return result[0].value;
        return '';
    };

    const handleClientChange = (selectedClients) => {
        if (selectedClients.length > 0 && selectedClients[0].clientId === -1)
            selectedClients.shift();
        setSelectedClients(selectedClients);
        let filteredFunds = [];
        selectedClients.map(
            (client) =>
            (filteredFunds = filteredFunds.concat(
                fundCollection.filter(function (item) {
                    return item.clientID === client.clientId;
                })
            ))
        );
        setSelectedFunds(filteredFunds);
    };

    const handleFundChange = (result) => {
        var selectedFunds = result.selectedFunds;
        if (selectedFunds.length > 0 && selectedFunds[0].fundId === -1)
            selectedFunds.shift();
        setSelectedFunds(selectedFunds);
    };

    const onJobSelection = (selectedDataList) => {
        if (selectedDataList === [] || selectedDataList.length === 0) {
            setSelectedJobs({ jobId: -1, jobName: 'SelectJob' });
            return;
        }
        let selectedData = selectedDataList[0];
        if (selectedData.jobId === -1)
            return;
        setSelectedJobs(selectedData);
    };

    const onDateChange = (fromDate) => {
        setFromDate(fromDate);
    };
    const getWireStatusName = (r) => {
        let wireStatus = wireStatusDetail.find(w => parseInt(w.code) === r.value);
        return wireStatus === undefined || isNull(wireStatus) ? 'NA' : wireStatus.name;
    }

    const failedJobNotificationDataCopy = cloneDeep(jobProcessCollection === undefined ? [] : jobProcessCollection);

    const isFirstColumn = (params) => {
        const displayedColumns = params.columnApi.getAllDisplayedColumns();
        return displayedColumns[0] == params.column;
    };

    const onGridReady = (params) => {
        setGridApi(params.api);
    };

    const setColumnDefs = () => {
        const headers = [
            {headerName: 'Select', field:'job'}
        ]
    }
}
